var
  ans:array[1..45000]of extended;
  man:array[1..500,1..500]of extended;
  a:array[1..500,1..500]of int64;
  ff:array[1..500]of boolean;
  d,na:array[1..500]of integer;
  road:array[1..500,1..500]of longint;
  dist,people:array[1..500,1..500]of integer;
  i,j,k,n,m,x,y,start,tail,now,now1:longint;

procedure sort(l,r: longint);
var
  i,j,x,y: longint;
begin
  i:=l;j:=r;x:=d[(l+r) div 2];
  repeat
    while d[i]<x do inc(i);
    while x<d[j] do dec(j);
    if not(i>j) then
      begin
        y:=d[i];d[i]:=d[j];d[j]:=y;
        y:=na[i];na[i]:=na[j];na[j]:=y;
        inc(i);dec(j);
      end;
  until i>j;
  if l<j then
    sort(l,j);
  if i<r then
    sort(i,r);
end;

begin
  assign(input,'transport.in');reset(input);
  assign(output,'transport.out');rewrite(output);
  readln(n,m);
  fillchar(ff,sizeof(ff),false);
  for i:=1 to m do begin
    read(x,y);
    road[x,y]:=i;
    road[y,x]:=i;
    dist[y,x]:=1;
    dist[x,y]:=1;
  end;
  for i:=1 to n do
    for j:=1 to n do begin
      a[i,i]:=1;
      read(people[i,j]);
      if people[i,j]>0 then ff[i]:=true;
    end;
  for k:=1 to n do
    for i:=1 to n do
      for j:=1 to n do begin
        if (dist[i,k]>0)and(dist[k,j]>0) then begin
          if (i<>j)and((dist[i,j]=0)or(dist[i,j]>dist[i,k]+dist[k,j])) then
            dist[i,j]:=dist[i,k]+dist[k,j];
        end;
      end;
  for i:=1 to n do begin
    if ff[i] then begin
      for j:=1 to n do begin
        d[j]:=dist[i,j];
        na[j]:=j;
      end;
      sort(1,n);
      for j:=2 to n do
        for k:=1 to n do begin
          now:=na[j];
          if (dist[now,k]=1)and(dist[i,k]+dist[k,now]=dist[i,now]) then
            inc(a[i,now],a[i,k]);
        end;
    end;
  end;
  for i:=1 to n do begin
    if ff[i] then begin
      for j:=1 to n do begin
        d[j]:=dist[i,j];
        na[j]:=j;
      end;
      fillchar(man,sizeof(man),0);
      sort(1,n);
      for j:=n downto 2 do begin
         for k:=1 to n do begin
           now:=na[j];
           if ((dist[now,k]=1)and(dist[i,k]+dist[k,now]=dist[i,now]))and(a[i,now]>0) then begin
             if a[i,now]>0 then begin
               ans[road[k,now]]:=ans[road[k,now]]+
               (people[i,now]+man[i,now])/a[i,now]*a[i,k];
             end;
             if a[i,k]>0 then
               man[i,k]:=man[i,k]+
               (people[i,now]+man[i,now])/a[i,now]*a[i,k];
           end;
         end;
      end;
    end;
  end;
  for i:=1 to m do
    writeln(ans[i]:0:1);
  close(input);close(output);
end.
