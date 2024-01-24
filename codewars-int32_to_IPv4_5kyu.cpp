/*
Take the following IPv4 address: 128.32.10.1

This address has 4 octets where each octet is a single byte (or 8 bits).

	1st octet 128 has the binary representation: 10000000
	2nd octet 32 has the binary representation: 00100000
	3rd octet 10 has the binary representation: 00001010
	4th octet 1 has the binary representation: 00000001

So 128.32.10.1 == 10000000.00100000.00001010.00000001

Because the above IP address has 32 bits, we can represent it as the unsigned 32 bit number: 2149583361

Complete the function that takes an unsigned 32 bit number and returns a string representation of its IPv4 address.

2149583361 ==> "128.32.10.1"
*/

#include <string>
#include <iostream>

std::string uint32_to_ip(uint32_t ip) {
	int sum = 0;

	std::string part1 = "0";
	std::string part2 = "0";
	std::string part3 = "0";
	std::string part4 = "0";

	if (ip != 0) {
		for (int i = 0; i < 8; ++i)
		{
			if (ip % 2 == 1)
			{
				sum += std::pow(2, i);
			}
			ip /= 2;
		}
		part1 = std::to_string(sum);
		sum = 0;
	}
	else { return "0.0.0.0"; }

	if (ip != 0) {
		for (int i = 0; i < 8; ++i)
		{
			if (ip % 2 == 1)
			{
				sum += std::pow(2, i);
			}
			ip /= 2;
		}
		part2 = std::to_string(sum);
		sum = 0;
	}

	if (ip != 0) {
		for (int i = 0; i < 8; ++i)
		{
			if (ip % 2 == 1)
			{
				sum += std::pow(2, i);
			}
			ip /= 2;
		}
		part3 = std::to_string(sum);
		sum = 0;
	}

	if (ip != 0) {
		for (int i = 0; i < 8; ++i)
		{
			if (ip % 2 == 1)
			{
				sum += std::pow(2, i);
			}
			ip /= 2;
		}
		part4 = std::to_string(sum);
		sum = 0;
	}

	return part4 + '.' + part3 + '.' + part2 + '.' + part1;
}

int main() {
	std::cout << uint32_to_ip(4154959208) << '\n';
	std::cout << uint32_to_ip(2154959208) << '\n';

	return 0;
}

/* Most clever solutions:
#include <sstream>

std::string uint32_to_ip(uint32_t ip)
{
  std::stringstream result{};
  result << (ip >> 24) << '.' << (ip >> 16 & 0xFF) << '.'
	  << (ip >> 8 & 0xFF ) << '.' << (ip & 0xFF);
  return result.str();
}

std::string uint32_to_ip(uint32_t ip)
{
  return
	std::to_string(ip>>24 & 255) + "." +
	std::to_string(ip>>16 & 255) + "." +
	std::to_string(ip>>8 & 255) + "." +
	std::to_string(ip & 255);
}

std::string uint32_to_ip(uint32_t ip)
{
  char result[16] = {0};
  uint8_t *ip_c = (uint8_t *)&ip;
  snprintf(result, sizeof(result), "%d.%d.%d.%d", ip_c[3], ip_c[2], ip_c[1], ip_c[0]);
  return std::string(result);
}

*/