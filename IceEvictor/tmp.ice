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
	
	interface Printer3 extends Printer,Printer2
	{
		void  printString3(string s);
	};
};