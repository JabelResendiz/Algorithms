## Manhattan distance

$$
d(p,q) = |x_p - x_q|+|y_p - y_q|
$$

### Farthest pair of points in Manhattan distance

$$
|x_p - x_q| = max(x_p - x_q, -x_p + xq)
$$

Then if we can try to have p such that $x_p$ has the plus sign, and then q must hace the negative sign:

$$
max_{p,q \in P} (x_p + (-x_q)) = max(x_p) + max(-x_q)
$$

d=2

$$
max (x_p - x_q + y_p - y_q) = max(x_p+y_p) + max(-x_q-y_q)
$$

$$


$$
