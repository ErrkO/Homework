(*Eric Oliver*)
(*CSCI 4230 *)
(*First Ocaml assignment*)

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
	| h::t -> rev_help (h::acc) t in
	rev_help [] lst;;

let member item lst =
	let rec mem_help acc = function
	| [] -> acc
	| h::t -> if h = item then true
		else (mem_help c);;

