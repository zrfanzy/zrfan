var
  p,s:array[1..1000]of char;
  pr:array[1..1000]of integer;
  c:char;
  i,w1,w2,j,k,start:integer;
begin
  read(c);
  while c<>chr(13) do begin
    inc(w1);
    p[w1]:=c;
    read(c);
  end;
  readln;
  read(c);
  while c<>chr(13) do begin
    inc(w2);
    s[w2]:=c;
    read(c);
  end;
  pr[1]:=0;
  k:=0;
  for i:=2 to w1 do begin
    while (k>0)and(p[k+1]<>p[i]) do k:=pr[k];
    if p[k+1]=p[i] then inc(k);
    pr[i]:=k;
  end;
  i:=1;
  while s[i]<>p[1] do inc(i);
  start:=i;
  j:=1;
  while i<=w2 do begin
    inc(i);inc(j);
    if s[i]<>p[j]then begin
      if pr[j-1]=0 then begin
        while (s[i]<>p[1])and(i<w2)do inc(i);
        start:=i;
        j:=1;
      end
      else begin
        dec(j);
        start:=i-j+pr[j]-1;
        j:=pr[j];
        dec(i);
      end;
    end;
    if j=w1 then begin
      writeln(start);
      halt;
    end;
  end;
end.