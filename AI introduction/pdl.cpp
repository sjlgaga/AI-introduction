#input
n of int in[1, 100];
d of(int in[0, 1000])[1 ~n][1 ~n];

#required
r of(int in[1, n])[1 ~n];
r[1] = 1;
r[n] = n;

#objective
minimize summation [d[r[i]][r[i + 1]]:forall i];