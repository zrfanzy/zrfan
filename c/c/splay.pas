type
        node=^pnode;
                pnode=record
                        key     :longint;
                        father,left,right       :node;
                end;
var
        n       :longint;
        root    :node;
        ch      :char;

        procedure splay(p:node);

                procedure zag(p:node);
                var
                        q       :node;
                begin
                        q:=p^.father;
                        p^.father:=q^.father;
                        if q=root then root:=p
                                else if q=q^.father^.left then q^.father^.left:=p
                                        else q^.father^.right:=p;
                        q^.left:=p^.right;
                        if q^.right<>nil then p^.right^.father:=q;
                        p^.right:=q;
                        q^.father:=p;
                        //also can update other informations ,must firt q second p
                end;

                procedure zig(p:node);
                var
                        q       :node;
                begin
                        q:=p^.father;
                        p^.father:=q^.father;
                        if q=root then root:=p
                                else if q=q^.father^.left then q^.father^.left:=p
                                        else q^.father^.right:=p;
                        q^.right:=p^.left;
                        if p^.left<>nil then p^.left^.father:=q;
                        p^.left:=q;
                        q^.father:=p;
                        //same as zag
                end;

        begin
                while p<>root do begin
                        if p=p^.father^.left then begin
                                if p^.father=root then zag(p)
                                        else if p^.father=p^.father^.left then begin
                                                zag(p^.father);
                                                zag(p);
                                        end else begin
                                                zag(p);
                                                zig(p);
                                        end;
                        end else begin
                                if p^.father=root then zig(p)
                                        else if p^.father=p^.father^.father^.right then begin
                                                zig(p^.father);
                                                zig(p);
                                        end else begin
                                                zig(p);
                                                zag(p);
                                        end;
                        end;
                end;
        end;

        procedure splay_insert;
        var
                tmp,p,q :node;
                num     :longint;
        begin
                readln(num);
                new(tmp);
                tmp^.key:=num;
                tmp^.left:=nil;
                tmp^.father:=nil;
                tmp^.right:=nil;
                if root=nil then root:=tmp
                        else begin
                                p:=root;
                                repeat
                                        q:=p;
                                        if num<=p^.key then p:=p^.left
                                                else p:=p^.right;
                                until p=nil;
                                tmp^.father:=q;
                                if num<=q^.key then q^.left:=tmp
                                        else q^.right:=tmp;
                                splay(tmp);
                        end;
        end;

        procedure splay_del;
        var
                num     :longint;
                p,q     :node;
        begin
                readln(num);
                p:=root;
                while (p<>nil) and (p^.key<>num) do
                        if p^.key>num then p:=p^.left
                                else p:=p^.right;
                if p=nil then begin
                        writeln('Can Not Find!');
                        exit;
                end;
                splay(p);
                if root^.left=nil then begin
                        root:=root^.right;
                        exit;
                end
                       else if root^.right=nil then begin
                                root:=root^.left;
                                exit;
                       end;
                p:=root^.right;
                root:=root^.left;
                q:=root;
                while q^.right<>nil do q:=q^.right;
                splay(q);
                root^.right:=p;
                p^.father:=q;
        end;

        procedure splay_find;
        var
                p       :node;
                x       :longint;
        begin
                readln(x);
                p:=root;
                while p<>nil do begin
                        if x=p^.key then begin
                                writeln('Find!');
                                splay(p);
                                exit;
                        end;
                        if x>p^.key then p:=p^.right
                                else p:=p^.left;
                end;
                writeln('Can Not Find!');
        end;

        procedure splay_getmax(q:node);
        var
                p       :node;
        begin
                if q=nil then begin
                        writeln('No Numbers!');
                        exit;
                end;
                p:=q;
                while p^.right<>nil do p:=p^.right;
                writeln(p^.key);
                splay(p);
        end;

        procedure splay_getmin(q:node);
        var
                p       :node;
        begin
                if q=nil then begin
                        writeln('No Numbers!');
                        exit;
                end;
                p:=q;
                while p^.left<>nil do p:=p^.left;
                writeln(p^.key);
                splay(p);
        end;

        procedure splay_prev;
        var
                num     :longint;
                p       :node;
        begin
                readln(num);
                p:=root;
                while (p<>nil) and (p^.key<>num) do
                        if num>p^.key then p:=p^.right
                                else p:=p^.left;
                if p=nil then begin
                        writeln('Can Not Find!');
                        exit;
                end;
                splay(p);
                splay_getmax(root^.left);
        end;

        procedure splay_succ;
        var
                num     :longint;
                p       :node;
        begin
                readln(num);
                p:=root;
                while (p<>nil) and (p^.key<>num) do
                        if num>p^.key then p:=p^.right
                                else p:=p^.left;
                if p=nil then begin
                        writeln('Can Not Find!');
                        exit;
                end;
                splay(p);
                splay_getmin(root^.right);
        end;

begin
        readln(n);
        root:=nil;
        while n>0 do begin
                read(ch);
                case ch of
                        'I' : splay_insert;
                        'D' : splay_del;
                        'F' : splay_find;
                        'X' : splay_getmax(root);
                        'N' : splay_getmin(root);
                        'P' : splay_prev;
                        'S' : splay_succ;
                end;
                dec(n);
        end;
end.