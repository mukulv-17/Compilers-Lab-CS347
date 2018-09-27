%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <iostream>
    #include <fstream>
    #include <list>
    #include <string>
    #include "functions.cpp"
    using namespace std;


    int yylex(void);
    void yyerror(const char* s);
    void yyerror2(const char* error_msg);

    #define YYDEBUG_VAL 1

    int flag = 0, level=0,sem_flag=0, offset, param_offset;
    int label = 0 ;
    vector<function> func_table;
    vector<variable> global_var_table;
    vector<int> dim_list;
    function *active_func_ptr;
    function call_name_ptr;
    vector<val_type> args_list;
    vector<variable> patch_list;
    val_type data_type;
    extern int  yylex();
    extern int yylineno;
    extern int lineno;
    FILE *fout = fopen("output.asm","w");
    // fclose(fout);
    // fout = fopen("output.asm","a");
%}

%union{
    node *Node;
}

%token <Node>   INTEGER TYPE_SPECIFIER RETURN PRINT IF ELSE WHILE BREAK BOOL_VAL IDENTIFIER COMMA 
%token <Node>   SEMICOLON OCB ORB CCB CRB OSB CSB CHARVAL STRING_LITERAL
%token <Node>   INC_OP DEC_OP AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP  
%token <Node>   LESS GREATER ASSIGN AND OR
%token <Node>   MINUS PLUS DIV TIMES MOD NOT
%start   translation_unit
%expect 6

%type <Node> error translation_unit declaration_list declaration empty variable_declaration variable_declaration_list function_declaration parameters parameter_list parameter_type_list statement compound_stmt stmt_list expression_stmt conditional_stmt iteration_stmt return_stmt break_stmt expression expr_suffix simple_expression logical_and_expr unary_relational_expression relational_expression additive_expression SUM_OP term MUL_OP postfix_expression func_call args arg_list constant open_round close_round close_curly comma semicolon id id_array dimlist

%%

translation_unit : declaration_list
{
    $$ = add_node("translation_unit",$1);
    $$->code = $1->code;
    $$->code = generate_final_code($$->code,global_var_table);
    if(flag==0&&sem_flag==0)
    {
        printf("Compilation successful.\n");
        ofstream output;
        output.open("tree.txt");
        // print_nodes($$,output);
        // print_symbol(global_var_table);
        // print_func(func_table);
        output.close();
        fprintf(fout,$$->code.c_str());
        printf("ASM file generated.\n");
    }
    else if(flag==1&&sem_flag==0)
    {
        printf("Syntax error(s) found.\n");
    }
    else if(flag==0&&sem_flag==1)
    {
        printf("Semantic error(s) found.\n");
    }
}
    ;


empty 
    : {$$ = NULL; }
    ;

declaration_list : declaration_list declaration
{
    $$ = add_node("declaration_list",$1,$2);
    $$->code = $1->code + $2->code;
}
     | declaration
{
    $$ = add_node("declaration_list",$1);
    $$->code = $1->code;
}
                 ;

declaration : function_declaration
{
   $$ = add_node("declaration",$1);
   $$->code = $1->code;
}
            | variable_declaration
{
   $$ = add_node("declaration",$1);
   $$->code = $1->code;
}
    | error {yyerror2("Missing Type Specifier "); flag = 1;$$ = NULL; exit(1);  }
    ;


variable_declaration            : TYPE_SPECIFIER variable_declaration_list semicolon
{
    string temp_code = "li $a0, 0\n";
    $$ = add_node("variable_declaration",$1,$2,$3);
    if(level)
    {
        for(int i=0; i< patch_list.size();i++)
        {
            if(check_varlist(global_var_table, func_table, patch_list[i].name) &&
             (!level || check_func_varlist(active_func_ptr, level, patch_list[i].name)))
            {
                variable k = patch_list[i];
                k.ele_type = $1->type;
                for (size_t i = 0; i < k.offset/4; i++) {
                    temp_code += "sw $a0, -"+to_string(offset + i*4)+"($fp)\n";
                }
                offset += k.offset;
                k.offset = -(offset - k.offset);
                active_func_ptr->local_var.push_back(k);

            }
            else
            {
                yyerror2("Function or variable with same name already declared");
                sem_flag = 1;
            }
        }
    }
    else
    {
        for(int i=0;i<patch_list.size();i++)
        {
            if(check_varlist(global_var_table, func_table, patch_list[i].name) && (!level || check_func_varlist(active_func_ptr, level, patch_list[i].name)))
            {
                    variable k = patch_list[i];
                    k.ele_type = $1->type;
                    k.offset = -1;
                    global_var_table.push_back(k);
            }
            else
            {
                    yyerror2("Function or variable with same name already declared");
                    sem_flag = 1;
            }
        }

    }
    $$->code = temp_code;
    patch_list.clear();
}
;


variable_declaration_list       : variable_declaration_list comma id_array
{
    $$ = add_node("variable_declaration_list",$1,$2,$3);
}
    | id_array

{
    $$ = add_node("variable_declaration_list",$1);
}
;

id_array : id OSB dimlist CSB
{
    $$ = add_node( "id_array" ,$1,$2,$3,$4);
    int temp_offset = 1;
    $$->name = $1->name;
    variable k($$->name,ARRAY,NONE,level);
    k.offset = temp_offset;
    for (size_t i = 0; i < dim_list.size(); i++) {
        k.dim_ptr.push_back(dim_list[i]);
        temp_offset *= dim_list[i];
    }
    k.offset = temp_offset*4;
    dim_list.clear();
    patch_list.push_back(k);
}
    |
        id
{
    $$ = add_node("id_array" ,$1);
    $$->name = $1->name;
    variable k($$->name,SIMPLE,NONE,level);
    k.offset = 4;
    patch_list.push_back(k);

}
;

id                      : IDENTIFIER
{
    $$ = add_node("id",$1);
    $$->name = $1->name;
}
;


dimlist : INTEGER comma dimlist
{
    $$ = add_node("dimlist",$1,$2,$3);
    dim_list.insert(dim_list.begin(), $1->val);
}

        | INTEGER

{
    $$ = add_node("dimlist",$1);
    dim_list.push_back($1->val);
}

;


function_declaration            : TYPE_SPECIFIER IDENTIFIER ORB
{
    level++;
    offset = 4;
    if($2->name == "main")
        param_offset = 4;
    else
        param_offset = 8;
    // offset = 8;
    // param_offset = 0;
    if(check_varlist(global_var_table, func_table, $2->name))
    {
        function cur_func($2->name ,$1->type);
        func_table.push_back(cur_func);
        active_func_ptr = &func_table.back();
    }
    else
    {
        yyerror2("Function or variable with same name is already declared.");
        sem_flag=1;
        function cur_func($2->name ,$1->type);
        active_func_ptr = &cur_func;
    }

} parameters close_round compound_stmt
{
    level--;
    string temp_code;
    if(active_func_ptr->name == "main")
        temp_code = "main:\n";
    else
        temp_code = "func_"+$2->name+":\n";
    temp_code += std::string("move $fp, $sp\n")
                + "sw $ra, 0($sp)\n"
                + "addiu $sp, $sp, -4\n";
    temp_code += "addiu $sp, $sp, -"+to_string(offset - 4) + "\n";
    // 
    temp_code += $7->code;
    temp_code += "lw $ra, 0($fp)\n";
    temp_code += "lw $fp, 4($fp)\n";
    if(active_func_ptr->name == "main")
        temp_code += "addiu $sp, $sp, 4\n";
    else
        temp_code += "addiu $sp, $sp, "+to_string(offset + param_offset)+"\n";
    temp_code += "jr $ra\n";
    // if(active_func_ptr->name == "main")
    //     temp_code += "li $v0,10\nsyscall";
    // else
    //     temp_code += "jr $ra\n";
    $$ = add_node("function_declaration",$1,$2,$3,$5,$7);
    // print_local_var(active_func_ptr);
    $$->code = temp_code;

}


;


parameters              : parameter_list
{
    // param_offset = 0;
    $$ = add_node("parameters",$1);
}
| empty
{
    // param_offset = 0;
    $$ = add_node("parameters",$1);
}
;

parameter_list          : parameter_list comma parameter_type_list
{
    $$ = add_node("parameter_list",$1,$2,$3);
}
    | parameter_type_list
{
    $$ = add_node("parameter_list",$1);
}
;

parameter_type_list     : TYPE_SPECIFIER IDENTIFIER
{
    $$ = add_node("parameter_type_list",$1,$2);
   variable k($2->name, SIMPLE, $1->type, 1);
   k.offset = param_offset;
   active_func_ptr->params.push_back(k);
   param_offset += 4;
}

;




statement               : expression_stmt
{
    $$ = add_node("statement",$1);
    $$->code = $1->code;
}
    | compound_stmt
{
    $$ = add_node("statement",$1);
    $$->code = $1->code;
}

    | conditional_stmt
{
    $$ = add_node("statement",$1);
    $$->code = $1->code;
}
    | iteration_stmt
{
    $$ = add_node("statement",$1);
    $$->code = $1->code;
}
    | return_stmt
{
    $$ = add_node("statement",$1);
    $$->type = $1->type;
    $$->val = $1->val;
    if(active_func_ptr->return_type != $$->type)
    {
        printf("Warning: Return type mismatch at line %d.\n",lineno);
    }
    $$->code = $1->code;
}
    | break_stmt
{
    $$ = add_node("statement",$1);
}
    | {patch_list.clear();} variable_declaration
{
    $$ = add_node("statement",$2);
    //patch_list.clear();
    $$->code = $2->code;
}
                        ;

compound_stmt           : OCB { level++; } stmt_list close_curly
{
    clear_vars(active_func_ptr, level);
    level--;
    $$ = add_node("compound_stmt",$1,$3,$4);
    $$->code = $3->code;

}
;

stmt_list               : stmt_list statement
{
    $$ = add_node("stmt_list",$1, $2);
    $$->code = $1->code + $2->code;
}
    | empty
{
    $$ = add_node("stmt_list",$1);
}
                        ;

expression_stmt         : expression semicolon
{
    $$ = add_node("expression_stmt",$1,$2);
    $$->code = $1->code;
}
                         ;

conditional_stmt        : IF  open_round expression close_round statement
{
    $$ = add_node("conditional_stmt",$1,$2,$3,$4,$5);

    $$->code= $3->code 
            + "li $t0,1" + "\n"
            + "blt  $a0,$t0," + "L_"+to_string(label)+"\n"
            + $5->code
            + "L_"+to_string(label)+":\n";
    label++;


}

    | IF open_round expression close_round statement ELSE statement
{
    $$ = add_node("conditional_stmt",$1,$2,$3,$4,$5,$6,$7);
    $$->code = $3->code 
             + "li $t0,1" + "\n"
             + "blt $a0,$t0, " + "L_"+to_string(label)+"\n";
    label++;

    $$->code = $$->code 
            +  $5->code
            +  "b L_" +to_string(label)+"\n"
            +  "L_"+to_string(label-1)+":"+ $7->code
            +  "L_"+to_string(label)+":";
    label++;
}
                        ;

iteration_stmt          : WHILE open_round expression close_round statement
{
    $$ = add_node("iteration_stmt",$1,$2,$3,$4,$5);
    $$->code= "\nL_"
        + to_string(label)+":\n"
        + $3->code 
        + "li $t0,1\n";
    label++;
    $$->code= $$->code + "blt $a0,$t0, " + "L_"+to_string(label)+"\n"
            + $5->code 
            + "j "+"L_"+to_string(label-1)+"\n"
            + "L_"+to_string(label)+":\n";
    label++;
}
;

return_stmt             : RETURN  semicolon
{
    $$ = add_node("return_stmt",$1,$2);
        $$->code=   std::string("lw $ra, 0($fp)\n")
            + "lw $fp, 4($fp)\n"
            + "addiu $sp, $sp, "+to_string(offset + param_offset)+"\n"
            + "jr $ra\n";
}
    | RETURN  expression semicolon
{
    $$ = add_node("return_stmt",$1,$2,$3);
    // see if need to update $a
    $$->code= $2->code 
        + "lw $ra, 0($fp)\n"
        + "lw $fp, 4($fp)\n"
        + "addiu $sp, $sp, "+to_string(offset + param_offset)+"\n"
        + "jr $ra\n";
    $$->type = $2->type;
};

break_stmt              : BREAK semicolon
{
    $$ = add_node("break_stmt",$1,$2);
}
;

expression              : id_array ASSIGN simple_expression
{
    $$ = add_node("expression",$1,$2,$3);
    if( check_declared(active_func_ptr,global_var_table,level,$1->name)) {
        variable var1 = retrieve_declared(active_func_ptr,global_var_table,level,$1->name);

         if(check_dimension(var1,patch_list, lineno)){
            int arr_offset = 0;
            arr_offset = cal_arr_offset(patch_list[patch_list.size()-1],var1);
            // printf("%d\n" ,cal_arr_offset(patch_list[patch_list.size()-1],var1));

            if(!coercible(var1.ele_type,$3->type)){
                yyerror2("Non-coercible types. Assignment failed.");
                sem_flag = 1;
            }
            else{
                if(var1.offset == -1){
                     $1->val = $3->val;
                    $$->type = BOOL;
                    $$->val = 1;
                    $$->code= $3->code 
                            + "la $t1," + var1.name + "\n"
                            + "sw $a0,($t1)\n";
                }
                else{
                    $1->val = $3->val;
                    $$->type = BOOL;
                    $$->val = 1;
                    $$->code= $3->code 
                            + "sw $a0,"+to_string(var1.offset+arr_offset)+"($fp)"+"\n"
                            + "li $a0,1\n";
                    //var1.offset($fp)
                }
            }
        }
    }
    else{
        yyerror2("Variable not declared");
        $$->type = ERROR;
        sem_flag = 1;
    }
}

    | id_array PLUS expr_suffix
{    
    ARITH_EXPR_NODE($$,$1,$2,$3, "la $t1," + var1.name + "\n"
                                + "lw $t2,($t1)\n"
                                + "add $a0,$a0,$t2\n"
                                ,"move $t1,$a0\n"
                                + "lw $a0,"+to_string(var1.offset)+"($fp)"+"\n"
                                + "add $a0,$a0,$t1\n");
}
    | id_array MINUS expr_suffix
{
    
    ARITH_EXPR_NODE($$,$1,$2,$3, "la $t1," + var1.name + "\n"
                                + "lw $t2,($t1)\n"
                                + "sub $a0,$a0,$t2\n"
                                , "move $t1,$a0\n"
                                + "lw $a0,"+to_string(var1.offset)+"($fp)"+"\n"
                                + "sub $a0,$a0,$t1\n");
}
    | id_array TIMES expr_suffix
{
    ARITH_EXPR_NODE($$,$1,$2,$3,"la $t1," + var1.name + "\n"
                                + "lw $t2,($t1)\n"
                                + "mult $a0,$t2\n"
                                + "mflo $a0\n"
                                , "move $t1,$a0\n"
                                + "lw $a0,"+to_string(var1.offset)+"($fp)"+"\n"
                                + "mult $a0,$t1\n"
                                + "mflo $a0\n");
}
    | id_array DIV expr_suffix
{
    ARITH_EXPR_NODE($$,$1,$2,$3, "la $t1," + var1.name + "\n"
                                + "lw $t2,($t1)\n"
                                + "div $a0,$t2\n"
                                + "mflo $a0\n"
                                , "move $t1,$a0\n"
                                + "lw $a0,"+to_string(var1.offset)+"($fp)"+"\n"
                                + "div $a0,$t1\n"
                                + "mflo $a0\n");
}
    | id_array MOD expr_suffix
{
    ARITH_EXPR_NODE($$,$1,$2,$3, "la $t1," + var1.name + "\n"
                                + "lw $t2,($t1)\n"
                                + "div $a0,$t2\n"
                                + "mfhi $a0\n"
                                , "move $t1,$a0\n"
                                + "lw $a0,"+to_string(var1.offset)+"($fp)"+"\n"
                                + "div $a0,$t1\n"
                                + "mfhi $a0\n");
}
    | simple_expression
{
    SIMPLE_NODE("expression",$$,$1);
}
                        ;

expr_suffix             : simple_expression
{
    SIMPLE_NODE("expr_suffix",$$,$1);
}
    | ASSIGN simple_expression
{
    // traverse
    // $$ = add_node("expr_suffix",$1,$2);
    SIMPLE_NODE("expr_suffix",$$,$2);
}


simple_expression             : ORB simple_expression OR_OP logical_and_expr close_round
{
    $$ = add_node("simple_expression",$1,$2,$3,$4,$5);
     $$->type = BOOL;
    $$->val = $2->val || $4->val;
    int label1 = label++;
    int label2 = label++;
    $$->code= $2->code 
            + "sw $a0,0($sp)\n"
            + "addiu $sp,$sp,-4\n"
            + $4->code 
            + "lw $t1,4($sp)\n"
            + "addiu $sp,$sp,4\n"
            + "move $t2,$a0\n"
            + "add $t1,$t1,$t2\n"
            + "li $t2,0\n"
            + "beq $t1,$t2,L_" + to_string(label1) + "\n"
            + "li $a0,1\n"
            + "b L_" + to_string(label2) +"\n"
            + "L_" + to_string(label1) + ": li $a0,0\n"
            + "L_" + to_string(label2) + ":\n";
}
    | logical_and_expr
{
    SIMPLE_NODE("simple_expression",$$,$1);
}
                        ;

logical_and_expr                : logical_and_expr AND_OP unary_relational_expression
{
    $$ = add_node("logical_and_expr",$1,$2,$3);
     $$->type = BOOL;
    $$->val = $1->val && $3->val;
    int label1 = label++;
    int label2 = label++;
    
    $$->code= $1->code 
            + "sw $a0,0($sp)\n"
            + "addiu $sp,$sp,-4\n"
            + $3->code 
            + "lw $t1,4($sp)\n"
            + "addiu $sp,$sp,4\n"
            + "move $t2,$a0\n"
            + "mult $t1,$t2\n"
            + "mflo $t1\n"
            + "li $t2,0\n"
            + "beq $t1,$t2,L_" + to_string(label1) + "\n"
            + "li $a0,1\n"
            + "b L_" + to_string(label2) +"\n"
            + "L_" + to_string(label1) + ": li $a0,0\n"
            + "L_" + to_string(label2) + ":\n";
}
    | unary_relational_expression
{
    $$ = add_node("logical_and_expr",$1);
    $$->type = $1->type;
    $$->val = $1->val;
    $$->code = $1->code;
}
                        ;

unary_relational_expression          
    : NOT unary_relational_expression
{
    $$ = add_node("unary_relational_expression",$1,$2);
     $$->type = BOOL;
    $$->val = ($2->val+1)%2;
    int label1 = label++;
    int label2 = label++;
    $$->code= $2->code 
            + "move $t1,$a0\n"
            + "li $t2,0\n"
            + "beq $t1,$t2,L_" + to_string(label1) + "\n"
            + "li $a0,1\n"
            + "b L_" + to_string(label2) +"\n"
            + "L_" + to_string(label1) + ": li $a0,0\n"
            + "L_" + to_string(label2) + ":\n";
}    
    | relational_expression
{
    $$ = add_node("unary_relational_expression",$1);
    $$->type = $1->type;
    $$->val = $1->val;
    $$->code = $1->code;
}
                        ;

relational_expression                
    : additive_expression GREATER additive_expression
{
    COMP_EXPR_NODE(>,"ble",$$,$1,$2,$3)
}
    | additive_expression LESS additive_expression
{
    COMP_EXPR_NODE(<,"bge",$$,$1,$2,$3)
}
    | additive_expression EQ_OP additive_expression
{
    COMP_EXPR_NODE(==,"bne",$$,$1,$2,$3)
}
    | additive_expression GE_OP additive_expression
{
    COMP_EXPR_NODE(>=,"blt",$$,$1,$2,$3)
}
    | additive_expression LE_OP additive_expression
{
    COMP_EXPR_NODE(<=,"bgt",$$,$1,$2,$3)
}
    | additive_expression NE_OP additive_expression
{
    COMP_EXPR_NODE(!=,"beq",$$,$1,$2,$3)
}

    | additive_expression
{
    $$ = add_node("relational_expression",$1);

    $$->type = $1->type;
    if($1->type == BOOL)
        $$->val = $1->val;
    else
        $$->val = ($1->val > 0);
    $$->code = $1->code;
}
                        ;

additive_expression                : additive_expression SUM_OP term
{
    $$ = add_node("additive_expression",$1,$2,$3);
    if(coercible($1->type,$3->type)==0)
    {
        yyerror2("Operation on non-coercible types");
        sem_flag = 1;
        $$->type = ERROR;
    }
    else
    {
        $$->type = compare_types($1->type,$3->type);
        if($2->val == 0)
        {
            
            $$->code= $1->code 
                    + "sw $a0,0($sp)\n"
                    + "addiu $sp,$sp,-4\n"
                    + $3->code 
                    + "lw $t1,4($sp)\n"
                    + "add $a0,$a0,$t1\n"
                    + "addiu $sp,$sp,4\n";
            $$->val = $1->val + $3->val;
        }
        else if($2->val == 1)
        {
            
            $$->code= $1->code 
                    + "sw $a0,0($sp)\n"
                    + "addiu $sp,$sp,-4\n"
                    + $3->code 
                    + "lw $t1,4($sp)\n"
                    + "sub $a0,$t1,$a0\n"
                    + "addiu $sp,$sp,4\n";
            $$->val = $1->val - $3->val;
        }
    }
}
    | term
{
    KEEP_VAL("additive_expression",$$,$1);
}
                        ;

SUM_OP                   : PLUS
{
    $$ = add_node("SUM_OP",$1);
    $$->val = 0;
}
    | MINUS
{
    $$ = add_node("SUM_OP",$1);
    $$->val = 1;
}
                        ;

term                    : term MUL_OP postfix_expression
{
    $$ = add_node("term",$1,$2,$3);
    if(coercible($1->type,$3->type)==0)
    {
        yyerror2("Operation on non-coercible types.");
        sem_flag = 1;
        $$->type = ERROR;
    }
    else
    {
        $$->type = compare_types($1->type,$3->type);
        if($2->val == 0)
        {
            $$->code= $1->code 
                    + "sw $a0,0($sp)\n"
                    + "addiu $sp,$sp,-4\n"
                    + $3->code 
                    + "lw $t1,4($sp)\n"
                    + "mult $a0,$t1\n"
                    + "mflo $a0\n"
                    + "addiu $sp,$sp,4\n";
            $$->val = $1->val * $3->val;
        }
        else if($2->val == 1)
        {
            $$->code = $1->code 
            + "sw $a0,0($sp)\n"
            + "addiu $sp,$sp,-4\n"
            + $3->code 
            + "lw $t1,4($sp)\n"
            + "div $t1,$a0\n"
            + "mflo $a0\n"
            + "addiu $sp,$sp,4\n";
            $$->val = $1->val / $3->val;
        }
        else if($2->val==2)
        {
            $$->code = $1->code 
            + "sw $a0,0($sp)\n"
            + "addiu $sp,$sp,-4\n"
            + $3->code 
            + "lw $t1,4($sp)\n"
            + "div $t1,$a0\n"
            + "mfhi $a0\n"
            + "addiu $sp,$sp,4\n";
            $$->val = $1->val % $3->val;
        }
    }
}
    | postfix_expression
{
    KEEP_VAL("term",$$,$1);
}
                        ;

MUL_OP                   : TIMES
{
    $$ = add_node("MUL_OP",$1);
    $$->val = 0;
}

    | DIV
{
    $$ = add_node("MUL_OP",$1);
    $$->val = 1;
}
    | MOD
{
    $$ = add_node("MUL_OP",$1);
    $$->val = 2;
}
;

postfix_expression                  : id_array
{
    $$ = add_node("postfix_expression",$1);
    if( check_declared(active_func_ptr,global_var_table,level,$1->name)) {
        variable var1 = retrieve_declared(active_func_ptr,global_var_table,level,$1->name);
       // printf("%d %d\n" ,patch_list.size() , var1.dim_ptr.size());
        //printf("%s\n",patch_list[patch_list.size()].name.c_str());
        if(patch_list[patch_list.size()-1].dim_ptr.size() == var1.dim_ptr.size() ){
            int res = 1;
            for(int i=0;i< var1.dim_ptr.size() ;i++){
                if(patch_list[patch_list.size()-1].dim_ptr[i] >= var1.dim_ptr[i]){
                    res=0;
                }
            }
            if(res == 1){
                if(var1.offset == -1){
                    $$->val = $1->val;
                    $$->type = var1.ele_type;
                    $$->code = "la $t1," + var1.name + "\nlw $a0,($t1)\n";
                }
                else{
                    $$->type = var1.ele_type;
                    $$->code= "lw $a0,"+to_string(var1.offset)+"($fp)\n";
                }
            }
            else{
                 yyerror2("indexes are out of bound\n");
            }
        }
        else{
            yyerror2("dimension mismatch\n");
        }
    }
    else{
        yyerror2("Variable not declared");
        $$->type = ERROR;
        sem_flag = 1;
    }
}
    | ORB expression close_round
{
    $$ = add_node("postfix_expression",$1,$2,$3);
    $$->type = $2->type;
    $$->val  =$2->val;
    $$->code = $2->code;
}

    |  func_call
{
    KEEP_VAL("postfix_expression",$$,$1)
}
    | constant
{
    SIMPLE_NODE("postfix_expression",$$,$1)
}
                        ;

func_call                    : IDENTIFIER ORB args close_round
{
    $$ = add_node("func_call",$1,$2,$3,$4);
    if(check_func_name(func_table, $1->name)) {
        yyerror2("Function not declared.");
        sem_flag = 1;
    }
    else {
        call_name_ptr = get_func(func_table, $1->name);
        if(match_args(call_name_ptr, args_list)) {
            $$->type = call_name_ptr.return_type;
            $$->code = $3->code + "jal func_" + call_name_ptr.name+"\n";
            // printf("hello %s\n", $$->code.c_str());
        }
        else
        {
            yyerror2("Argument mismatch in function call");
            sem_flag = 1;
            $$->type = ERROR;
        }
        args_list.clear();
    }
}
;

args                    : arg_list
{
    $$ = add_node("args",$1);
    $$->code = $1->code + "sw $fp, 0($sp)\naddiu $sp, $sp, -4\n";
}

    | empty
{
    $$ = add_node("args",$1);
    $$->code = "sw $fp, 0($sp)\naddiu $sp, $sp, -4\n";
}
                        ;

arg_list                : arg_list comma expression
{
    $$ = add_node("arg_list",$1,$2,$3);
    args_list.push_back($3->type);
    string temp_code = $3->code + "sw $a0, 0($sp)\naddiu $sp, $sp, -4\n";
    $$->code = temp_code + $1->code;


}
    | expression
{
    $$ = add_node("arg_list",$1);
    args_list.push_back($1->type);
    $$->type = $1->type;
    $$->code = $1->code + "sw $a0, 0($sp) \naddiu $sp, $sp, -4\n";
}
                        ;

constant                : INTEGER
{
    $$ = add_node("constant",$1);
    $$->type = INT;
    $$->val = $1->val;
    $$->code = "li $a0,"+to_string($1->val)+"\n";
}
    | BOOL_VAL
{
    $$ = add_node("constant",$1);
    $$->type = BOOL;
    $$->val = $1->val;
    $$->code = "li $a0,"+to_string($1->val)+"\n";
}
    | CHARVAL
{
    $$ = add_node("constant" ,$1);
    $$->type = CHAR;
    $$->val = $1->val;
    $$->code = "li $a0,"+to_string($1->val)+"\n";
}
                        ;

open_round               : ORB

{
    $$ = add_node("open_round",$1);
}
    | error {yyerror2("'(' expected after IF or WHILE "); flag = 1; $$ = NULL; };


close_round             : CRB

{
    $$ = add_node("close_round",$1);
}
    | error {yyerror2("Missing ')' "); flag = 1; $$ = NULL;};


close_curly            : CCB
{
    $$ = add_node("close_curly",$1);
}
    | error {yyerror2("Missing '}' "); flag = 1; $$ = NULL;};

comma                   : COMMA
{
    $$ = add_node("comma",$1);
}
                        ;

semicolon               : SEMICOLON
{
    $$ = add_node("semicolon",$1);
}
    | error {lineno--;yyerror2("Missing ';' or ',' ");lineno++; flag = 1; $$ = NULL;
};

%%
extern char* yytext;
extern int lineno;
extern int column;
char* input_filename="test.txt";
extern FILE* yyin;

void printLine(int lineno){
    int line = 1;
    char temp[500];//line buffer
    FILE* yyerrFile = fopen(input_filename,"r");

    while(fgets(temp,sizeof temp, yyerrFile)!=NULL){
        if(line == lineno){
            printf("%s",temp);
            if(temp[strlen(temp)-1]!='\n')
                printf("\n");
            break;
        }else{
            line++;
        }

    }
    fclose(yyerrFile);
}
void yyerror(const char* error_msg)
{
    //called by bison on syntax error
    fflush(stdout);
}
void yyerror2(const char* error_msg)
{
    fflush(stdout);
    printf("\tError: %s near line number: %d\n", error_msg,lineno);
    printLine(lineno);
//  printf("%*s\n%*s\n", column, "^", column, error_msg);
    exit(1);
}

int main(int argc, char* argv[]){
    if(argc>1)
        input_filename = argv[1];
    yyin = fopen(input_filename,"r");

    #if YYDEBUG
        yydebug=YYDEBUG_VAL;
    #endif
    int err;
    do { 
        err = yyparse();
    } while(!feof(yyin));
    if(err==0)
        printf("Done parsing file\n");
    fclose(yyin);
    return 0;
}