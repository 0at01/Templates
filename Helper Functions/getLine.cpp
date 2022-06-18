ll n;
cin>>n;
vector<string> v;
cin.ignore();
for(ll i=0;i<n;i++)
{
  string s;
  getline(cin,s);
  v.push_back(s);
}
for(auto&u:v) cout<<u<<endl;