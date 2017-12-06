% Eric Oliver
% CSCI 4230
% Assignment 7

% returns true if M is female and a parent of C
mother(M,C) :- female(M) , parent(M,C).

% returns true if F is male and a parent of C
father(F,C) :- male(F), parent(F,C).

% returns true if s1 and s2 share the same parent
sibling(S1,S2) :- parent(P,S1), parent(P,S2).

% returns true if C1 and C2 are first cousins
first_cousin(C1,C2) :- parent(P1,C1), sibling(P1,P2), parent(P2,C2).

% returns true if D descends from A
ancestor(A,D) :- parent(A,D).
ancestor(A,D) :- parent(A,B), ancestor(B,D).

% returns true if P1 and P2 share A as an ancestor
common_ancestor(A,P1,P2) :- not(P1 = P2), ancestor(A,P1), ancestor(A,P2).

% returns true if R is the reverse of L
do_reverse(L, R) :- do_reverse(L, R, []).

do_reverse([], L, L).
do_reverse([H|T], L, TR) :- do_reverse(T, L, [H|TR]).

% returns true if the result is the list with I added to the front
insert(X, [], [X]):- !.
insert(X, [X1|L1], [X, X1|L1]):- X=<X1, !.
insert(X, [X1|L1], [X1|L]):- insert(X, L1, L).

% returns true if the result contains the original list sorted in order
insertion_sort([], []):- !.
insertion_sort([X|L], S):- insertion_sort(L, S1), insert(X, S1, S).

% returns true if L3 is a union of L1 and L2
is_union([], L2, L3).
is_union([H|L1t], L2, L3) :- memberchk(H, L2), !, is_union(L1t, L2, L3).
is_union([H|L1t], L2, [H|L3t]) :- is_union(L1t, L2, L3t).

% returns true if L3 is an intersection of L1 and L2
is_intersection([], _, []).
is_intersection([H|L1t], L2, L3) :- memberchk(H, L2), !, L3 = [H|L3t],is_intersection(L1t, L2, L3t).
is_intersection([_|L1t], L2, L3) :- is_intersection(L1t, L2, L3).