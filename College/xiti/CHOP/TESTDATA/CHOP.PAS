var t:array[1..100] of integer;
    i,j,k,n,p:integer;
    f:array[0..100,0..50] of integer;
begin
   assign(input,'chop.in');
   assign(output,'chop.out');
   reset(input);rewrite(output);
   readln(n,k);
   for i:=1 to n do read(t[i]);
     if 2*(k+3)>n then
       begin
        write(-1);
        halt;
       end;
   for i:=1 to n do
     for j:=n downto i+1 do
      if t[i]>=t[j] then
        begin
          P:=t[i];
          t[i]:=t[j];
          t[j]:=p;
        end;
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
    for j:=1 to k+3 do
     begin
      f[i,j]:=f[i-1,j-1];
        for p:=1 to i-2 do
          if f[p,j-1]+(t[i]-t[i-1])*(t[i]-t[i-1])>f[i,j] then f[i,j]:=f[p,j-1]+(t[i]-t[i-1])*(t[i]-t[i-1]);
     end;
  write(f[n,k+3]);
end.