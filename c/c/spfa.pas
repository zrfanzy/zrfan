const
  maxp=10000;
var
  p,c,s,t:longint;
  a,b:array[1..maxp,0..maxp]of longint;
  d:array[1..maxp]of integer;
  v:array[1..maxp]of boolean;
  dist:array[1..maxp]of longint;
  head,tail:longint;

begin
  fillchar(d,sizeof(d),0);
  fillchar(v,sizoef(v),false);
  for j:=1 to p do dist[j]:=maxlongint;
  dist[s]:=0;
  v[s]:=true;d[1]:=s;
  while head <=tail do begin
    now:=d[head];
    for i:=1 to b[now,0]do
      if dist[b[now,i]]>dist[now]+a[now,b[now,i]] then begin
        dist[b[now,i]]:=dist[now]+a[now,b[now,i]];
        if not v[b[now,i]] then begin
          inc(tail);
          d[tail]:=b[now,i];
          v[b[now,i]]:=true;
        end;
      end;
      v[now]:=false;
      inc(head);
  end;
end.