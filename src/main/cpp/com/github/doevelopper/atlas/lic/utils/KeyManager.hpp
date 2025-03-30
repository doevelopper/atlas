namespace cfs::algo::filters::kalman
{
    class OptionDescription
    {
        LOG4CXX_DECLARE_STATIC_LOGGER
 public:
        OptionDescription() noexcept;
        OptionDescription(const OptionDescription&) noexcept = default;
        OptionDescription(OptionDescription&&) noexcept =  default;
        OptionDescription& operator=(const OptionDescription&) noexcept = default;
        OptionDescription& operator=(OptionDescription&&) noexcept = default;
        virtual ~OptionDescription() noexcept;
    protected:
    private:
    };
}
