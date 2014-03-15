var
 a:array[1..100] of record
                     l,r,f:integer;
                     x:integer;
                     n:integer;
                    end;
 c,n,m,i,z:integer;
procedure insertx(x,f:integer);
var
 z:integer;
begin
 inc(a[f].n);
 if x<a[f].x then z:=a[f].l else z:=a[f].r;
 if a[z].x=0 then
  begin
   a[z].x:=x; a[z].f:=f; a[z].n:=0;
   if x<a[f].x then a[f].l:=z else a[f].r:=z;
   splay(z);
   exit;
  end;
 insertx(x,z);
end;
function find(x,f:integer):integer;
begin
 if a[f].x=0 then exit(0);
 if a[f].x=x then exit(f);
 if a[f].x>x then exit(find(x,a[f].l));
 if a[f].x<x then exit(find(x,a[f].r));
end;
procedure deletex(f:integer);
var
 l,r:integer;
begin
 l:=a[f].l; r:=a[f].r;
 if (a[l].x=0) and (a[r].x=0) then
  begin
   if a[a[f].f].l=f then a[a[f].f].l:=0 else a[a[f].f].r:=0;
   a[f].f:=0;
  end
 else if a[r].x=0 then
  begin
   a[a[f].f].l:=a[f].l; a[a[f].l].f:=a[f].f;
   a[f].f:=0;
  end
 else if a[l].x=0 then
  begin
   a[a[f].f].r:=a[f].r; a[a[f].r].f:=a[f].f;
   a[f].f:=0;
  end
 else
  begin
  end;
end;
begin
 readln(m);
 for i:=1 to m do
  begin
   read(c,n);
    case c of
     1: insertx(n,1);
     2: begin z:=find(n,1); deletex(z); end;
     3: searchk(n,1,k);
     4: begin z:=find(n,1); splay(z); writeln(min(a[searchright(a[z].l)],a[searchleft(a[z].r)])); end;
    end;
  end;
end.