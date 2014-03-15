var
 h:array[1..100] of integer;
 l:array[1..100] of integer;
 c,x,y,m,i:integer;
function searchhead(x:integer):integer;
begin
 if h[x]=x then searchhead:=x
 else
  begin
   searchhead:=searchhead(h[x]);
   l[x]:=l[x]+l[h[x]]; h[x]:=searchhead;
  end;
end;
procedure join(x,y:integer);
var
 z:integer;
begin
 z:=searchhead(x); l[z]:=1; h[z]:=y;
end;
begin
 assign(input,'disjoint_sets.in'); reset(input);
 assign(output,'disjoint_sets.out'); rewrite(output);
 readln(m); for i:=1 to m do begin h[i]:=i; l[i]:=0; end;
 readln(m);
 for i:=1 to m do
  begin
   read(c);
    case c of
     1: begin readln(x,y); join(x,y); end;
     2: begin readln(x); writeln(searchhead(x)); end;
     3: begin readln(x,y); if searchhead(x)=searchhead(y) then writeln('Yes') else writeln('No'); end;
     4: begin readln(x); writeln(l[x]); end;
    end;
  end;
 close(input); close(output);
end.