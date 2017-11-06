(*Eric Oliver*)
(*CSCI 4230*)
(*Assignment 6*)

type ’a bst = Empty | Node of ’a * ’a bst * ’a bst ;;

type ks_item = { name : string ; value : int ; weight : int }
type knapsack = { total_value : int ; total_weight : int ; contents : ks_item list };;

type expr_type = Int_type | Float_type | Bool_type ;;
type type_error = Expected_bool | Expected_same | Expected_num ;;

exception Type_error of type_error ;;

type operation = Add_op | Sub_op | Mult_op | Div_op | Less_op | Greater_op | Less_eq_op | Greater_eq_op | Eq_op | Not_eq_op ;;

type expression = Int_lit o f int | Float_lit o f float | Bool_lit o f bool | If_expr o f expression * expression * expression |
 Op_expr o f expression * operation * expression ;;

let bst_insert tree item =
	let rec insert_help tree item =
	| [] -> tree

let bst_contains tree item = 
	let rec contains_help tree item =


let bubble_sort arr = 
	let rec bubble_help arr =

let knapsack_add ks item = 
	let rec add_help ks item = 


let solve_knapsack items capacity = 
	let rec solve_help items capacity =


let  process_if_expr cond_type then_expr_type else_expr_type = 


let process_operation op expr1_type expr2_type = 


let infer_type expr = 


let 