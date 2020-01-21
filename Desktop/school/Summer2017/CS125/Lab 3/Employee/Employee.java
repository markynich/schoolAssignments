/*********************************************************************
Name:Mark-Nicholas Magsakay
Course: CS125-05
Lab #: Lab 3
Submission Date: 10:00pm, Wednesday 7/12/17
Brief Description:
**********************************************************************/

public class Employee {
	private String employeeName;
	private String employeeNumber;
	private String hireDate;
	
	//default constructor implementation
	public Employee(){
		employeeName = "no name yet";
		employeeNumber = "no number yet";
		hireDate = "no date yet";
	}	//end of default constructor
	
	//parameterized constructor implementation
	public Employee(String employName, String employNumber, String date){
		setEmployeeName(employName);
		setEmployeeNumber(employNumber);
		setHireDate(date);
	}	//end of parameter constructor method implementation
	//getEmployeeName method implementation
	public String getEmployeeName()
	{
		return employeeName;
	} //end of getEmployeeName
	public String getEmployeeNumber()
	{
		return employeeNumber;
	}	//end of getEmployee Number
	public String gethireDate()
	{
		return hireDate;
	} //end of getHireDate
	
	//mutator methods
	//set method implementations
	public void setEmployeeName(String employName)
	{
		employeeName = employName;
	} //end of SetEmployeeName
	public void setEmployeeNumber(String employNumber)
	{
		if (employNumber.length() == 5
			&& Character.isDigit(employNumber.charAt(0))
			&& Character.isDigit(employNumber.charAt(1))
			&& Character.isDigit(employNumber.charAt(2))
			&& employNumber.charAt(3) == '-'
			&& (employNumber.charAt(4) >= 'A'
			&& employNumber.charAt(4) <= 'M'))
		{
			employeeNumber = employNumber;
		} //1st
		else
		{
			employeeNumber = " Invalid Number ";
		} //2nd
		} //end of setEmployeeNumber
		//setHireDate method implementation
		public void setHireDate(String date)
		{
			hireDate = date;
		} //end of setHiredate
		public String toString()
		{
			String result = "";
			result = "Employee name: " + employeeName + "\n"
					+ "Employee number: " + employeeNumber + "\n"
					+ "Employee hire date: " + hireDate;
			return result;
	}	// end of toString
} //end of Employee Program
