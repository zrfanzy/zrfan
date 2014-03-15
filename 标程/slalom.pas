var
  tree:array[1..1000000,1..7]of longint;
  w:array[1..50000]of longint;
  a:array[1..50000,1..2]of longint;
  order:array[1..50000]of longint;
  n,num,i,maxy,maxi,k,j:longint;

function max(p,q:longint): longint;
begin
  if p>q then max:=p else max:=q;
end;

function maxl(m,p,q,l,r:longint) : longint;
var
  x,x1,x2:longint;
begin
  x:=(p+q)div 2;
  if (p=q)or((p=l)and(r=q)) then begin
    maxl:=tree[m,1];
    num:=tree[m,5];
  end
  else if (l>x) then begin
    maxl:=maxl(m*2+1,x+1,q,l,r);
    num:=tree[m*2+1,5];
  end
  else if (r<=x) then begin
    maxl:=maxl(m*2,p,x,l,r);
    num:=tree[m*2,5];
  end
  else begin
    x1:=maxl(m*2,p,x,l,x);
    x2:=maxl(m*2+1,x+1,q,x+1,r);
    maxl:=max(x1,x2);
    if x1>x2 then num:=tree[m*2,5]
    else num:=tree[m*2+1,5];
  end;
end;

function maxr(m,p,q,l,r:longint) : longint;
var
  x,x1,x2:longint;
begin
  x:=(p+q)div 2;
  if (p=q)or((p=l)and(r=q)) then begin
    maxr:=tree[m,2];
    num:=tree[m,6]
  end
  else if (l>x) then begin
    maxr:=maxr(m*2+1,x+1,q,l,r);
    num:=tree[m*2+1,6];
  end
  else if (r<=x) then begin
    maxr:=maxr(m*2,1,x,l,r);
    num:=tree[m*2,6];
  end
  else begin
    x1:=maxr(m*2,p,x,l,x);
    x2:=maxr(m*2+1,x+1,q,x+1,r);
    maxr:=max(x1,x2);
    if x1>x2 then num:=tree[m*2,6]
    else num:=tree[m*2+1,6];
  end;
end;

procedure changel(m:longint);
begin
  if m<>1 then begin
    if tree[m,1]>tree[m div 2,1] then begin
      tree[m div 2,1]:=tree[m,1];
      tree[m div 2,5]:=tree[m,5];
      tree[m div 2,3]:=tree[m,3];
      changel(m div 2);
    end
  end;
end;

procedure changer(m:longint);
begin
  if m<>1 then begin
    if tree[m,2]>tree[m div 2,2] then begin
      tree[m div 2,2]:=tree[m,2];
      tree[m div 2,4]:=tree[m,4];
      tree[m div 2,6]:=tree[m,6];
      changer(m div 2);
    end
  end;
end;

procedure insert(m,p,q,l:longint);
var
  x:longint;
begin
  x:=(p+q)div 2;
  if (p=q) then begin
    tree[m,6]:=m;
    tree[m,5]:=m;
    tree[m,7]:=order[i];
    if m>maxi then maxi:=m;
    tree[m,2]:=maxl(1,1,maxy,1,x-1)+1;
    tree[m,4]:=num;
    if l<>maxy then begin
      tree[m,1]:=maxr(1,1,maxy,l+1,maxy)+1;
      tree[m,3]:=num;
    end
    else tree[m,1]:=1;
    changel(m);changer(m);
  end
  else begin
    if l<=x then insert(m*2,p,x,l)
    else insert(m*2+1,x+1,q,l);
  end;
end;

procedure qsort(l,r:longint);
var
  i,j,x,y:longint;
begin
  i:=l;j:=r;
  x:=a[(l+r)div 2,2];
  repeat
    while a[i,2]<x do inc(i);
    while x<a[j,2] do dec(j);
    if not(i>j) then begin
      y:=a[i,2];a[i,2]:=a[j,2];a[j,2]:=y;
      y:=a[i,1];a[i,1]:=a[j,1];a[j,1]:=y;
      y:=order[i];order[i]:=order[j];order[j]:=y;
      inc(i);dec(j);
    end;
  until i>j;
  if l<j then qsort(l,j);
  if i<r then qsort(i,r);
end;

begin
  readln(n);
  for i:=1 to n do begin
    read(a[i,1],a[i,2]);
    order[i]:=i;
    if a[i,1]>maxy then maxy:=a[i,1]
  end;
  qsort(1,n);
  for i:=n downto 1 do begin
    insert(1,1,maxy,a[i,1]);
  end;
  if tree[1,1]>tree[1,2] then k:=5 else k:=6;
  writeln(max(tree[1,1],tree[1,2]));
  w[1]:=tree[tree[1,k],7];
  j:=tree[1,k-2];
  k:=11-k;
  for i:=2 to max(tree[1,1],tree[1,2])do begin
    w[i]:=tree[tree[j,k],7];
    j:=tree[j,k-2];
    k:=11-k;
  end;
  for i:=max(tree[1,1],tree[1,2])downto 1 do write(w[i],' ');
end.
