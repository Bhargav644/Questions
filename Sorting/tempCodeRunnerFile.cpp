  int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    divide_and_conquer(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }