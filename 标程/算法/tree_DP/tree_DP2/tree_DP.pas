var
 c:array[1..100] of integer;
 l:array[1..100] of integer;
 x:array[0..100,0..100] of integer;
 a:array[1..100,0..100,0..1] of integer;
 son:array[1..100,0..100] of integer;
 n,k,i,j,p,q,z:integer;
function min(x,y:integer):integer;
begin
 if x>y then exit(y) else exit(x);
end;
begin
 assign(input,'tree_DP3.in'); reset(input);
 assign(output,'tree_DP3.out'); rewrite(output);
 readln(n);
 for i:=1 to n do
  begin
   read(c[i],son[i,0]);
   for j:=1 to son[i,0] do read(son[i,j]);
  end;
 for i:=1 to n do begin a[i,0,0]:=0; a[i,0,1]:=0; a[i,1,0]:=c[i]; a[i,1,1]:=c[i]; end;
 for i:=n downto 1 do
  begin
   for j:=1 to son[i,0] do inc(l[i],l[son[i,j]]);
   inc(l[i]);
   fillchar(x,sizeof(x),0); k:=0;
   for j:=1 to son[i,0] do
    begin
     x[j,0]:=0; k:=k+l[son[i,j]];
     for p:=1 to k do
      begin
       x[j,p]:=x[j-1,p];
       z:=min(p,l[son[i,j]]);
       for q:=1 to z do
         if x[j,p]<x[j-1,p-q]+a[son[i,j],q,1] then x[j,p]:=x[j-1,p-q]+a[son[i,j],q,1];
      end;
    end;
   a[i,0,0]:=0; a[i,0,1]:=0;
   for j:=1 to l[i] do
    begin
     a[i,j,1]:=x[son[i,0],j-1]+c[i];
     a[i,j,0]:=a[i,j,1];
     for p:=1 to son[i,0] do
       if a[i,j,0]<a[son[i,p],j,0] then a[i,j,0]:=a[son[i,p],j,0];
    end;
  end;
 readln(p);
 for i:=1 to p do begin read(k); writeln(a[1,k,0]); end;
 close(input); close(output);
end.
