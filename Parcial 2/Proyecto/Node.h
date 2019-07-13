#pragma once
#include <string>
#include <iostream>

using namespace std;

class Sort;

/**
 * The Node class that contains the personal data of persons
 */
class Node 
{
	//Estos datos solo son para agregarlos para una persona
	protected:
		/**
		 * Name of the person
		 */
		string name;
	
		/**
		 * LastName of the person
		 */
		string lastName;
	
		/**
		 * E-mail address
		 */
		string email;
	
		/**
		 * The birth day of the person
		 */
		unsigned char birthDay;
	
		/**
		 * The birth month of the person
		 */
		unsigned char birthMonth;
	
		/**
		 * The birth year of the person
		 */
		unsigned char birthYear;
	
	public:

		/**
		 * TODO implement
		 * Returns the Name of the person
		 * @return [std::string] The name
		 */
		const string getName();
	
		/**
		 * TODO implement
		 * Sets the Name of the person
		 * @param [std::string] The name
		 * @return [void]
		 */
		void setName(string _name);
	
		/**
		 * TODO implement
		 * Returns the LastName of the person
		 * @return [std::string] The lastname
		 */
		const string getLastName();
	
		/**
		 * TODO implement
		 * Sets the LastName of the person
		 * @param [std::string] The lastname
		 * @return [void]
		 */
		void setLastName(string _last_name);
	
		/**
		 * TODO implement
		 * Returns the E-mail address of the person
		 * @return [std::string] The E-mail address
		 */
		const string getEmail();
	
		/**
		 * TODO implement
		 * Sets the E-mail of the person
		 * @param [std::string] The E-mail
		 * @return [void]
		 */
		void setEmail(string _email);
	
		/**
		 * TODO implement
		 * Sets the birthdate of the person
		 * @param [unsigned char] day
		 * @param [unsigned char] month
		 * @param [unsigned char] year
		 * @return [void]
		 */
		void setBirthDate(unsigned char _day, unsigned char _month, unsigned char _year);
	
		/**
		 * TODO implement
		 * Returns the full name in format "LastName Name"
		 * @return [std::string] The full name
		 */
		const string getFullName();
	
		/**
		 * TODO implement
		 * Returns the calculated age
		 * @return [unsigned int] The age
		 */
		const unsigned int getAge();
	
		/**
		 * Deletes every linked node
		 */
		virtual ~Node() {};
};

/**
 * The SingleNode class to representate a single linked list, inherits from Node
 */
class SingleNode : public Node 
{
	protected:
	
		/**
		 * The pointer to the next node
		 */
		SingleNode* next;
	
		/**
		 * Adds friendship to Sort class
		 */
		friend class Sort;
	
		/**
		 * Adds friendship to List class
		 */
		friend class SingleList;
	
	public:

		/**
		 * TODO implement
		 * Overrides the ">" operator allowing: (SingleNode & > SingleNode &)
		 * @param [const SingleNode &] The right side of the operation
		 * @return [bool] Whether is the left side is greater than the right side
		 */
		bool operator > ( SingleNode &_right_s);
	
		/**
		 * TODO implement
		 * Overrides the "<" operator allowing: (SingleNode & < SingleNode &)
		 * @param [const SingleNode &] The right side of the operation
		 * @return [bool] Whether is the left side is lower than the right side
		 */
		bool operator < (SingleNode &_right_s);
	
		/**
		 * TODO implement
		 * Concatenates the full data of this nodes and the followings to the output stream
		 */
		friend std::ostream & operator << (std::ostream &_out, SingleNode &_node);
	
		/**
		 * TODO implement
		 * Concatenates the full data of this nodes and the followings to the output stream
		 */ 
		friend std::istream & operator >> (std::istream &_input, SingleNode &_node);
	
		/**
		 * TODO implement
		 * Deletes every linked node
		 */
		virtual ~SingleNode();
};

/**
 * The DoubleNode class to representate a double linked list, inherits from Node
 */
class DoubleNode : public Node 
{
	protected:
	
		/**
		 * The pointer to the next node
		 */
		DoubleNode* next;
	
		/**
		 * The pointer to the previous node
		 */
		DoubleNode* prev;
	
		/**
		 * Adds friendship to Sort class
		 */
		friend class Sort;
	
		/**
		 * Adds friendship to List class
		 */
		friend class DoubleList;
	
	public:
	
		/**
		 * TODO implement
		 * Overrides the ">" operator allowing: (DoubleNode & > DoubleNode &)
		 * @param [const DoubleNode &] The right side of the operation
		 * @return [bool] Whether is the left side is greater than the right side
		 */
		bool operator > (DoubleNode &_right_s);
	
		/**
		 * TODO implement
		 * Overrides the "<" operator allowing: (DoubleNode & < DoubleNode &)
		 * @param [const DoubleNode &] The right side of the operation
		 * @return [bool] Whether is the left side is lower than the right side
		 */
		bool operator < (DoubleNode &_right_s);
	
		/**
		 * TODO implement
		 * Concatenates the full data of this nodes and the followings to the output stream
		 */
		friend std::ostream & operator << (std::ostream &_out, DoubleNode &_d_noude);
	
		/**
		 * TODO implement
		 * Concatenates the full data of this nodes and the followings to the output stream
		 */
		friend std::istream & operator >> (std::istream &_input, DoubleNode &_d_node);
	
		/**
		 * TODO implement
		 * Deletes every linked node
		 */
		virtual ~DoubleNode();
};
