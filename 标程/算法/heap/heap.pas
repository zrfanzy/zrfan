var
 a:array[1..100] of integer;
 c,n,m,i,k:integer;
procedure exchange(x,y:integer);
var
 z:integer;
begin
 z:=a[x]; a[x]:=a[y]; a[y]:=z;
end;
procedure verseup(n:integer);
var
 z:integer;
begin
 if n=1 then exit;
 if a[n]<a[n div 2] then exchange(n,n div 2);
 verseup(n div 2);
end;
procedure versedown(n:integer);
var
 z:integer;
begin
 if n*2>k then exit;
 if n*2=k then z:=n*2
 else
  begin
   if a[n*2]<a[n*2+1] then z:=n*2 else z:=n*2+1;
  end;
 if a[n]<=a[z] then exit;
 exchange(n,z);
 versedown(z);
end;
begin
 assign(input,'heap.in'); reset(input);
 assign(output,'heap.out'); rewrite(output);
 readln(m); k:=0;
 for i:=1 to m do
  begin
   read(c);
    case c of
     1: begin readln(n); inc(k); a[k]:=n; verseup(k); end;
     2: begin writeln(a[1]); a[1]:=a[k]; dec(k); versedown(1); end;
    end;
  end;
 close(input); close(output);
end.