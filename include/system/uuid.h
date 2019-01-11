#ifndef _UUID_
#define _UUID_

#include <string>
#include <boost/uuid/uuid.hpp>

namespace smeta3d
{
	class __declspec(dllexport) CUUID final
	{
		public:

			CUUID() {}
			CUUID(const std::string& strUUID);

			void FromStr(const std::string& strUUID);
			std::string ToStr() const;

			static CUUID Generate();

	private:
	friend inline bool operator<(const smeta3d::CUUID& lft_, const smeta3d::CUUID& rgh_);

		boost::uuids::uuid m_UUID;		

	};
	inline bool operator<(const smeta3d::CUUID& lft_, const smeta3d::CUUID& rgh_)
	{
		return lft_.m_UUID < rgh_.m_UUID;
	}
} // end namespace smeta3d


#endif // _EVENT_MANAGE_
