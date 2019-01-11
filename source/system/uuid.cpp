#include "system/uuid.h"
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace smeta3d
{
	CUUID::CUUID(const std::string & strUUID)
	{
		FromStr(strUUID);
	}

	void CUUID::FromStr(const std::string & strUUID_)
	{
		boost::uuids::string_generator gen;
		try
		{
			m_UUID = gen(strUUID_);
		}
		catch (...)
		{

		}
	}
	std::string CUUID::ToStr() const
	{
		std::string strUUID = boost::uuids::to_string(m_UUID);
		return strUUID;
	}
	CUUID CUUID::Generate()
	{
		CUUID id;
		id.m_UUID = boost::uuids::random_generator()();
		return id;
	}
}