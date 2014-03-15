const
  maxn=10;
  maxm=10;
var
  g:array[1..maxn,1..maxm]of boolean;
  y:array[1..maxm]of boolean;
  link:array[1..maxm]of longint;
  i,ans,n,m,j,k:longint;

function find(p:longint):boolean;
var
  i,j:longint;
begin
  for i:=1 to m do
    if (g[p,i])and(not y[i]) then begin
      y[i]:=true;
      if (link[i]=0)or(find(link[i]))then begin
        find:=true;
        link[p]:=i;
        exit;
      end;
    end;
    find:=false;
end;

begin
  readln(n,m);
  for i:=1 to n do
    for j:=1 to m do begin
      read(k);
      if k=0 then g[i,j]:=false else g[i,j]:=true;
    end;
  for i:=1 to n do begin
    fillchar(y,sizeof(y),0);
    if find(i) then inc(ans);
  end;
  writeln(ans);
end.