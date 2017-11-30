mother(M,C) :- female(M) , parent(M,C).

father(F,C) :- male(F), parent(F,C).

sibling(S1,S2) :- parent(P,S1), parent(P,S2).

first_cousin(C1,C2) :- parent(P1,C1), sibling(P1,P2), parent(P2,C2).

ancestor(A,D) :- parent(A,D).
ancestor(A,D) :- parent(A,B), ancestor(C,D).

common_ancestor(A,P1,P2) :- first_cousin(P1,P2).
common_ancestor(A,P1,P2) :- first_cousin(B,C), parent(C,P2), parent(B,P1), common_ancestor(A,B,C).