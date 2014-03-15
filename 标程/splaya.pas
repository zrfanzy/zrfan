var
  fa,fa1,lc1,rc1,lc,rc:array[0..1000]of integer;
  s,num:array[0..1000]of integer;
  n,i,root:integer;

procedure left(p:integer);
begin
  fa1:=fa;lc1:=lc;rc1:=rc;
  fa[p]:=fa1[fa1[p]];
  if fa1[fa1[p]]<>0 then begin
  if lc1[fa1[fa1[p]]]=fa1[p] then begin
    lc[fa1[fa1[p]]]:=p;
  end
  else rc[fa1[fa1[p]]]:=p;
  end;
  rc[p]:=fa1[p];
  fa[fa1[p]]:=p;
  lc[fa1[p]]:=rc1[p];
  rc[fa1[p]]:=rc1[fa1[p]];
  if rc1[p]<>0 then
  fa[rc1[p]]:=fa1[p];
  if rc1[fa1[p]]<>0 then
  fa[rc1[fa1[p]]]:=fa1[p];
end;

procedure right(p:integer);
begin
  fa1:=fa;lc1:=lc;rc1:=rc;
  fa[p]:=fa1[fa1[p]];
  if fa1[fa1[p]]<>0 then begin
  if lc1[fa1[fa1[p]]]=fa1[p] then begin
    lc[fa1[fa1[p]]]:=p;
  end
  else rc[fa1[fa1[p]]]:=p;
  end;
  lc[p]:=fa1[p];
  fa[fa1[p]]:=p;
  lc[fa1[p]]:=lc1[fa1[p]];
  rc[fa1[p]]:=lc1[p];
  if lc1[fa1[p]]<>0 then
  fa[lc1[fa1[p]]]:=fa1[p];
  if lc1[p]<>0 then
  fa[lc1[p]]:=fa1[p];
end;

procedure splay(p:integer);
begin
  if fa[fa[p]]=0 then begin
    if lc[fa[p]]=p then left(p)
    else right(p);
  end
  else if ((lc[fa[p]]=p)and((lc[fa[fa[p]]]=fa[p])or(fa[fa[p]]=0)))then begin
    left(fa[p]);left(p);
  end
  else if ((rc[fa[p]]=p)and((rc[fa[fa[p]]]=fa[p])or(fa[fa[p]]=0))) then begin
    right(fa[p]);right(p);
  end
  else begin
    if lc[fa[p]]=p then begin
      left(p);right(p);
    end
    else begin
      right(p);left(p);
    end;
  end;
end;

procedure insert(p,x:integer);
begin
  if s[p]=0 then begin
    root:=i;
    s[p]:=i;
  end
  else begin
    if num[s[p]]>x then begin
      if lc[p]=0 then begin
        lc[p]:=i;
        fa[i]:=p;
        s[i]:=i;
        while fa[i]<>0 do
          splay(i);
        root:=i;
      end
      else begin
        insert(lc[p],x);
      end;
    end
    else if num[s[p]]<x then begin
      if rc[p]=0 then begin
        rc[p]:=i;
        fa[i]:=p;
        s[i]:=i;
        while fa[i]<>0 do
          splay(i);
        root:=i;
      end
      else begin
        insert(rc[p],x);
      end;
    end;
  end;
end;

procedure dg(p:integer);
begin
  if p<>0 then
  writeln(num[p],'left',num[lc[p]],'right',num[rc[p]]);
  if lc[p]<> 0 then
  dg(lc[p]);
  if rc[p]<>0 then
  dg(rc[p]);
end;

begin
  readln(n);
  root:=1;
  for i:=1 to n do begin
    read(num[i]);
    insert(root,num[i]);
    dg(root);
    writeln;
  end;
  dg(root);
end.
