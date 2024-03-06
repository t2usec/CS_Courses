void CreateSeqList(SeqList &lst, char s[]) {
	lst.data = new char[lst.length + 1];
	lst.length = strlen(s);
	for (int i=0; i<strlen(s); i++) {
		lst.data[i] = s[i];
	}
	lst.data[lst.length] = '\0';
}

void Insert(SeqList &lst, char c) {
	lst.length++;
	char *newData = new char[lst.length + 1];
	newData[0] = c;
	strcpy(newData + 1, lst.data);
	delete[] lst.data;
	lst.data = newData;
}