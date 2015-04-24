#pragma once

namespace RawData
{
	const char STOP_CHAR = '@';
	size_t ReadSizeUntilStopChar(std::istream &in);

	void WriteString(std::string const& str, std::ostream &out);
	std::string ReadString(std::istream &in);

	void WriteUnsigned(unsigned u, std::ostream &out);
	unsigned ReadUnsigned(std::istream &in);
}
