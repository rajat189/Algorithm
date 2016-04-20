pair <int ,int> task[100000];
inline bool cmp(const pair <int, int> &a, const pair <int, int> &b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}
main(){
	sort(task,task+n,cmp);
}
