module Demo
{
	interface Printer
	{
		void  printString(string s);
	};
	
	interface Printer2
	{
		void  printString2(string s);
	};
	
	interface callBack
	{
		void set(int i);
	};
	
	interface Printer3 extends Printer,Printer2
	{
		void  printString3(string s);
		void setInt(int j);
		void setCall(callBack * cb);
	};
	class Printf //包含在ice行不通
	{
		string vison();
		Printer prt1;
		Printer2 ptr2;
	};
};