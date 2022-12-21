#pragma once
#include <string_view>
#include <stdexcept>
#include <sstream>


#ifdef _DEBUG
#define FILE_NAME extract_file_name(__FILE__)
#define REQUIRE(requirement, message) ms::require(requirement, message, FILE_NAME, __FUNCTION__, __LINE__)
#define EXCEPTION(message) ms::require(false, message, FILE_NAME, __FUNCTION__, __LINE__)
#else
#define LOCATION 
#define REQUIRE(requirement, message)
#define EXCEPTION(message)
#endif


namespace
{
	inline std::string_view extract_file_name(std::string_view __FILE__macro)
	{
		const auto num_remove = __FILE__macro.rfind("\\") + 1;
		__FILE__macro.remove_prefix(num_remove);

		return __FILE__macro;
	}
}


namespace ms
{
	inline void require(const bool requirement, const std::string_view& message,
		const std::string_view& file_name, const std::string_view& function_name, const int num_line)
	{
		if (!requirement)
		{
			std::ostringstream os;

			os << "\n==============================EXCEPTION========================================\n";
			os << "File\t\t: " << file_name << "\n";
			os << "Function\t: " << function_name << "\n";
			os << "Line\t\t: " << num_line << "\n";
			os << "Message\t\t: " << message.data() << "\n";
			os << "==============================EXCEPTION========================================\n\n";

			throw std::runtime_error(os.str());
		}
	}
}