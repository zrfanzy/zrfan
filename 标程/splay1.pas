var
  fa,fa1,lc1,rc1,lc,rc:array[0..1000]of integer;
  s,data,size,num:array[0..1000]of integer;
  n,i,root,t:integer;

procedure left(x:integer);
var
  y:integer;
begin
  y:=fa[x];
  rc[y]:=lc[x];
  if lc[x]<>0 then
    fa[lc[x]]:=y;
  fa[x]:=fa[y];
  if fa[y]<>0 then begin
    if y=lc[fa[y]] then
      lc[fa[y]]:=x
    else rc[fa[y]]:=x;
  end;
  lc[x]:=y;
  fa[y]:=x;
end;

procedure right(x:integer);
var
  y:integer;
begin
  y:=fa[x];
  lc[y]:=rc[x];
  if rc[x]<>0 then
    fa[rc[x]]:=y;
  fa[x]:=fa[y];
  if fa[y]<>0 then begin
    if y=lc[fa[y]] then
      lc[fa[y]]:=x
    else rc[fa[y]]:=x;
  end;
  rc[x]:=y;
  fa[y]:=x;
end;

procedure splay(x:integer);
var
  y:integer;
begin
  y:=0;
  while (fa[x]<>y) do begin
    if fa[fa[x]]=y then begin
      if x=lc[fa[x]] then right(x)
      else left(x);
    end
    else if fa[x]=lc[fa[fa[x]]] then begin
      if x=lc[fa[x]] then begin
        right(fa[x]);
        right(x);
      end
      else begin
        left(x);
        right(x);
      end;
    end
    else begin
      if x=rc[fa[x]] then begin
        left(fa[x]);
        right(x);
      end
      else begin
        right(x);
        left(x);
      end;
    end;
  end;
  if y=0 then root:=x;
end;

procedure insert(v:integer);
var
  x:integer;
begin
  x:=root;
  while true do begin
    inc(size[x]);
    if (v<data[x]) then begin
      if lc[x]=0 then break
      else x:=lc[x];
    end
    else
      if rc[x]=0 then break
      else x:=rc[x];
  end;
  inc(t);
  data[t]:=v;
  fa[t]:=x;
  size[t]:=1;
  if v<data[x] then lc[x]:=t
  else rc[x]:=t;
  splay(t);
end;

procedure dg(x:integer);
begin
  if data[x]<>0 then begin
    writeln(data[x],'left',data[lc[x]],'right',data[rc[x]]);
    dg(lc[x]);
    dg(rc[x]);
  end;
end;

begin
  readln(n);
  for i:=1 to n do begin
    read(num[i]);
    insert(num[i]);
  end;
  dg(n);
end.
