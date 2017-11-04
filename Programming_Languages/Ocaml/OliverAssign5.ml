(*Eric Oliver*)
(*CSCI 4230 *)
(*First Ocaml assignment*)

(*#use "OliverAssign5.ml";;*)

let t1 = [1;2;3;4;5;6;8;10];;

let t2 = [2;4;6;7;8;9;10;11];;

let t3 = [1;2;3;4;5;6;7;8;9];;

let t4 = [6;2;8;1;4;9;7;3;5];;

let t5 = [3;2;1];;

let sqaure x = x *. x;;

let rad a b c = (sqaure b -. 4.0 *. a *. c );;

let quadratic a b c =
	if rad a b c < 0.0 then
		Printf.printf "No_Real_Roots \n"
	else
		let x1 = ((-.b +. sqrt(rad a b c)) /. (2.0 *. a))
			and x2 = ((-.b -. sqrt(rad a b c)) /. (2.0 *. a))
		in
		Printf.printf "( %.5f , %.5f ) \n" x1 x2;;

let third (_,_,a) = a;;

let reverse lst = 
	let rec rev_help acc = function
	| [] -> acc
	| f::b -> rev_help (f::acc) b in
		rev_help [] lst;;

let member item lst =
	let rec mem_help item lst =
		match lst with
		| [] -> false
		| f::b -> if f = item then true
			else mem_help item b
		in mem_help item lst;;

let union lst lst2 =
	let rec un_help lst lst2 =
		match lst, lst2 with
		| [],_ -> lst2
		| _,[] -> lst
		| fx::bx, fy::by ->
			if member fx lst2 then un_help bx lst2 else fx :: un_help bx lst2
		in un_help lst lst2;;


let intersect lst lst2 =
	let rec inter_help lst lst2 =
		match lst with
		| [] -> lst
		| fx::bx ->
			if member fx lst2 then fx :: inter_help bx lst2 else inter_help bx lst2
		in inter_help lst lst2;;

let lessthen pivot lst =
	let rec less_help pivot lst =
		match lst with
		| [] -> lst
		| f::b -> if f < pivot then f :: less_help pivot b
			else less_help pivot b
		in less_help pivot lst;;

let greaterthan pivot lst =
	let rec great_help pivot lst =
		match lst with
		| [] -> lst
		| f::b -> if f >= pivot then f :: great_help pivot b
			else great_help pivot b
		in great_help pivot lst;;

let partition pivot lst =
	(lessthen pivot lst , (greaterthan pivot lst));;

let quicksort lst =
	let rec quick_help lst =
	match lst with
    | [] -> lst
    | f::b -> let tup = partition f b in
    	quick_help (fst tup) @ [f] @ quick_help (snd tup)
    in quick_help lst;;