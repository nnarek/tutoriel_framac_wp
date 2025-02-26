for first case we have following wp

```
wp(if b1&&b2 then c else skip, p) =
((b1&&b2) ==> wp(c,p)) && (!(b1&&b2) ==> wp(skip,p)) =
((b1&&b2) ==> wp(c,p)) && (!(b1&&b2) ==> p) 
```

for second case we following wp

```
wp(if b1 then (if b2 then c else skip) else skip, p) =
(b1 ==> wp(if b2 then c else skip,p)) && (!b1 ==> wp(skip,p)) = 
(b1 ==> [(b2 ==> wp(c,p)) && (!b2 ==> p)]) && (!b1 ==> p) = 
[b1 && b2 ==> wp(c,p)] && [(b1&&!b2) ==> p] && (!b1 ==> p) =
[b1 && b2 ==> wp(c,p)] && [(b1&&!b2) ==> p] && (!b1 && (!b2||b2) ==> p) =
[b1 && b2 ==> wp(c,p)] && [(b1&&!b2) ==> p] && [(!b1 &&!b2) ==> p] && [(!b1&&b2) ==> p] =
[b1 && b2 ==> wp(c,p)] && [!(b1&&b2) ==> p]
```

hence two programs have same weakest precondition
