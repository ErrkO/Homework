(*Eric Oliver*)
(*CSCI 4230*)
(*Assignment 6*)

(*#use "OliverAssign6.ml";;*)

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
	match item with
	| [] -> Node([],item,[])
	| Node(left,k,right) ->
		if item < k then Node(insert_help item left,k,right)
		else Node(left,k,insert_help item right);;


let bst_contains tree item = 
	let rec contains_help tree item =
	| []-> false
	| Node(left,k,right) ->
		if item < k then contains_help item left
		else if item = k then true
		else contains_help item right;;

let bubble_sort arr = 
	let rec bubble_help arr =
  	let sorted = function
  	| h1 :: h2 :: tl when h1 > h2 ->
        h2 :: bubble_help (h1 :: tl)
  	| h1 :: tl ->
        h1 :: bubble_help tl
  	| tl -> tl
	in
		if lst = sorted then
    		lst
		else
    		bubble_help sorted;;

let knapsack_add ks item = 
	ks2 = {total_value = ks.total_value+item.value; total_weight = ks.total_weight+item.weight ; contents = ks.contents @ item};;

let solve_knapsack items capacity = 
	let rec solve_help ks lst = 
	match lst with
	| [] = ks
	| f::b -> if f == [] then
		ks
	else
		if f.weight + ks.total_weight < capacity then
			knapsack_add ks f
			solve_help ks b
		else
			ks
	in solve_help tks b;;

let process_if_expr cond_type then_expr_type else_expr_type = 
	if cond_type != Bool_type then
		raise Expected_bool of type_error
	else
		


let process_operation op expr1_type expr2_type = 


let infer_type expr = 


let 