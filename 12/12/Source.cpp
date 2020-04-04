#include <windows.h>
#include <string>  
#include <iostream>
#include <exception>

#define FIRST_COMPARABLE_VALUE 0x200
#define SECOND_COMPARABLE_VALUE 0x400

const int BUFFER_SIZE = 0x1000;

char mFileBuffer[BUFFER_SIZE];
DWORD mNumberOfBytesRead;


namespace CMyExceptionSpace {
	class CMyException : public std::exception {
	protected:
		std::string mEMessage;
		std::string mEDesciption;

	public: 
		CMyException() {}
		CMyException(std::string pEMessage, std::string pEDesciption) {
				mEMessage = pEMessage;
				mEDesciption = pEDesciption;
		}
		virtual const char* what() const throw()
		{
			std::cout << "Message: " << this->mEMessage << std::endl;
			std::cout << "Description: " << this->mEDesciption << std::endl;
			return NULL;
		}

	};

}

namespace CMyException2Space {
	class CMyException2 : public CMyExceptionSpace::CMyException{
		protected: 
			std::string mEEXDesciption;


		public:

			CMyException2(std::string pEMessage, std::string pEDesciption, std::string pEEXDesciption) {
				mEMessage = pEMessage;
				mEDesciption = pEDesciption;
				mEEXDesciption = pEEXDesciption;
			}

		virtual const char* what() const throw()
		{
			CMyExceptionSpace::CMyException::what();
			std::cout << "Extra Description: " << this->mEEXDesciption << std::endl;
			return NULL;
		}
	};
}

namespace CMyException3Space {
	class CMyException3 : public CMyExceptionSpace::CMyException {
		protected: 
			std::string mEEXDesciption;

		public:
			CMyException3(std::string pEMessage, std::string pEDesciption, std::string pEEXDesciption) {
				mEMessage = pEMessage;
				mEDesciption = pEDesciption;
				mEEXDesciption = pEEXDesciption;
			}
			virtual const char* what() const throw()
			{
				CMyExceptionSpace::CMyException::what();
				std::cout << "Extra Description: " << this->mEEXDesciption << std::endl;
				return NULL;
			}
	};
}


namespace Func1Space {
	HANDLE Func1(std::string pFilePath) {

		if (pFilePath.substr(0, pFilePath.find_last_of(".")) == "source")
			throw CMyExceptionSpace::CMyException(
				"Program was interrupted by Func1", 
				"Cause's file name contains forbiden substrign"
			);
		if(pFilePath.substr(pFilePath.find_last_of(".") + 1) == "h")
			throw CMyException2Space::CMyException2(
				"Program was interrupted by Func1",
				"Cause's file name contains forbiden substrign",
				"Unhadled file's extention"
			);
		HANDLE mHFile; 
		mHFile = CreateFile((std::wstring(pFilePath.begin(), pFilePath.end())).c_str(),
			GENERIC_READ,
			FILE_SHARE_READ,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL);
		return mHFile;
	}
}
namespace Func2Space {
	void Func2(HANDLE pHFile) {
		if (ReadFile(pHFile, &::mFileBuffer, BUFFER_SIZE, &mNumberOfBytesRead, NULL)
				&& (mNumberOfBytesRead > FIRST_COMPARABLE_VALUE)) {
			throw CMyException3Space::CMyException3(
				"Program was interrupted by Func2",
				"Read file exception" ,
				"A count of read bytes greater than const value"
			);
		}
	}
}
namespace Func3Space {
	void Func3(HANDLE pHFile) {
		if (pHFile < (HANDLE)SECOND_COMPARABLE_VALUE) {
			CloseHandle(pHFile);
			throw CMyExceptionSpace::CMyException(
				"Program was interrupted by Func3",
				"File pointer exception"
			);
		}
		CloseHandle(pHFile);
	}
}

namespace FuncHadlerSpace {
	void FuncHandler(std::string pFilePath) {
		try {
			HANDLE mHFile = Func1Space::Func1(pFilePath);
			Func2Space::Func2(mHFile);
			Func3Space::Func3(mHFile);
		}
		catch (CMyExceptionSpace::CMyException & Exception){
			Exception.what();
		}
		catch (CMyException2Space::CMyException2 & Exception) {
			Exception.what();
		}
		catch (CMyException3Space::CMyException3 & Exception) {
			Exception.what();
		}
	}
}


void main(){
	std::string mFilePath = "qsource.qh";
	std::cout << "Read file: " << mFilePath << std::endl;

	FuncHadlerSpace::FuncHandler(mFilePath);

	std::cin;
}