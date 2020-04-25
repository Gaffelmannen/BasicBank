class Bank
{
	private:
		int acc_no;
		char name[20];
		char acc_type[20];
		double balance;
	public:
		void Open();
		void Deposit();
		void Withdraw();
		void Inspect();
};
