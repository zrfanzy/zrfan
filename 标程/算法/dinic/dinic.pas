var
 left,c:array[1..100,1..100] of integer;
 widen:array[0..100,1..2] of integer;
 level:array[1..100] of integer;
 next:array[1..100,0..100] of integer;
 lnext:array[1..100,0..100] of integer;
 i,j,m,n,x,y,s,t,maxflow:integer;
procedure levelgraph;
var
 a:array[1..200] of integer;
 head,tail,i:integer;
begin
 a[1]:=s; level[s]:=1; head:=1; tail:=1;
 while head<=tail do
  begin
   for i:=1 to next[a[head],0] do
     if level[a[head]]+1<level[next[a[head],i]] then
      begin
       level[next[a[head],i]]:=level[a[head]]+1;
       inc(lnext[a[head],0]); lnext[a[head],lnext[a[head],0]]:=next[a[head],i];
       inc(tail); a[tail]:=next[a[head],i];
      end;
   inc(head);
  end;
end;
procedure modify(k,z:integer);
var
 i,j:integer;
begin
 if k=0 then exit;
 dec(left[widen[k,1],widen[k+1,1]],z);
 if left[widen[k,1],widen[k+1,1]]=0 then
  begin
   for i:=1 to next[widen[k,1],0] do
     if next[widen[k,1],i]=widen[k+1,1] then break;
   for j:=i to next[widen[k,1],0]-1 do next[widen[k,1],j]:=next[widen[k,1],j+1];
   dec(next[widen[k,1],0]);
  end;
 if left[widen[k+1,1],widen[k,1]]=0 then
  begin
   inc(next[widen[k+1,1],0]); next[widen[k+1,1],next[widen[k+1,1],0]]:=widen[k,1];
  end;
 inc(left[widen[k+1,1],widen[k,1]],z);
 modify(k-1,z);
end;
function min(a,b:integer):integer;
begin
 if a<b then exit(a) else exit(b);
end;
procedure flow(f,k:integer);
var
 i:integer;
 b:boolean;
begin
 if f=t then begin inc(maxflow,widen[k-1,2]); widen[k,1]:=t; modify(k-1,widen[k-1,2]); exit; end;
 b:=false;
 for i:=1 to lnext[f,0] do
   if level[lnext[f,i]]=level[f]+1 then
    begin
     b:=true; widen[k,1]:=f; widen[k,2]:=min(widen[k-1,2],left[f,lnext[f,i]]); flow(lnext[f,i],k+1);
    end;
 if b=false then level[f]:=n;
end;
begin
 assign(input,'dinic6.in'); reset(input);
 assign(output,'dinic.out'); rewrite(output);
 readln(s,t);
 readln(n,m);
 for i:=1 to m do
  begin
   readln(x,y,j); c[x,y]:=j; inc(next[x,0]); next[x,next[x,0]]:=y;
  end;
 left:=c;
  repeat
   for i:=1 to n do level[i]:=n+1; fillchar(lnext,sizeof(lnext),0); levelgraph;
   if level[t]=n+1 then break;
   widen[0,2]:=maxint; flow(s,1);
  until false;
 writeln(maxflow);
 close(input); close(output);
end.
