in general hoare rule is following
```
{R/\b} a {P}     {R/\~b} c {P}
------------------------------
   {R} if b then a else c {P}
```

by replacing a by skip command we will get
```
{R/\b} skip {P}     {R/\~b} c {P}
------------------------------
   {R} ifnot b then c {P}
```
which is same as 
```
R/\b ==> P     {R/\~b} c {P}
------------------------------
   {R} ifnot b then c {P}
```


by replacing all branches by skip we will get 
```
R/\b ==> P     R/\~b ==> P
------------------------------
   {R} if b then skip else skip {P}
```
which is same as 
```
        R ==> P
------------------------------
   {R} if b then skip else skip {P}
```