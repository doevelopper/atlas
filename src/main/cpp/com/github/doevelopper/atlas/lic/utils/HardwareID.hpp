
#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LIC_UTILS_HARDWAREID_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LIC_UTILS_HARDWAREID_HPP



#include <com/github/doevelopper/atlas/lic/interface/IHardwareIdProvider.hpp>

namespace com::github::doevelopper::atlas::lic::utils
{
    class HardwareID : public interface::IHardwareIdProvider
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
 public:
        HardwareID() noexcept;
        HardwareID(const HardwareID&) noexcept = default;
        HardwareID(HardwareID&&) noexcept =  default;
        HardwareID& operator=(const HardwareID&) noexcept = default;
        HardwareID& operator=(HardwareID&&) noexcept = default;
        virtual ~HardwareID() noexcept;

        std::string getHardwareId() override;
        std::vector<std::string> getHardwareComponents() override;
        bool matchesHardwareId(const std::string& hardwareId) override;
        std::string getStableFingerprint() override;
        std::string generateHardwareId();

    protected:
    private:
        std::string getProcessorId();
        std::string getMotherboardId();
        std::string getDiskId();
        std::string getMacAddress();

        /**
         * @brief Get CPU information
         * @return CPU identifier string
         */
        std::string getCpuInfo();

        /**
         * @brief Get motherboard information
         * @return Motherboard identifier string
         */
        std::string getMotherboardInfo();

        /**
         * @brief Get disk drive information
         * @return Primary disk identifier string
         */
        std::string getDiskInfo();

        /**
         * @brief Get network adapter information
         * @return MAC address of primary network adapter
         */
        std::string getNetworkAdapterInfo();

        /**
         * @brief Calculate a hash of the combined hardware information
         * @param components Vector of hardware component identifiers
         * @return Hash string
         */
        std::string calculateHash(const std::vector<std::string>& components);
    };
}
#endif
