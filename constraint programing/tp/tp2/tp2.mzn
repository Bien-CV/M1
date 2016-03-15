include "globals.mzn";
int: n = 10;
array[1..n] of var 1..n: q; % q[1],...,q[n] de domaine 1..n
constraint alldifferent(q);
constraint forall(i in 1..n, j in i+1..n) (abs(q[j] - q[i]) != j - i);
solve satisfy;
output ["q = ", show(q), "\n"];
