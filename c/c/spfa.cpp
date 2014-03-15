memset(d,0,sizeof(d));
memset(v,false,sizeof(v));
for (j=1;j<=p;j++) dis[j]=maxlongint;
dist[s]=0;v[s]=true;d[1]=s;
head=1,tail=1;
while (head<=tail){
      now=d[head]l
      for(i=1;i<=b[now][0])
         if (i=1;i<=b[now][0])
            if (dist[b[now][i]]>dist[now]+a[now][b[now][i]]){
               dist[b[now][i]]=dist[now]+a[now][b[now][i]];
               if (!v[b[now][i]]){
                  d[++tail]=b[now][i];
                  v[b[now][i]]=true;
               }
            }      
         v[now]=false;head++;
}
