#ifndef COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_ENCRYPTEDFILEAPPENDER_HPP
#define COM_GITHUB_DOEVELOPPER_ATLAS_LOGGING_ENCRYPTEDFILEAPPENDER_HPP

#include <log4cxx/logger.h>
#include <log4cxx/appender.h>
#include <log4cxx/helpers/file.h>
#include <log4cxx/helpers/pool.h>
#include <log4cxx/spi/loggingevent.h>
#include <log4cxx/spi/appenderattachableimpl.h>
#include <log4cxx/helpers/exception.h>
#include <log4cxx/helpers/iosfwd.h>
#include <log4cxx/helpers/pointer.h>
#include <log4cxx/helpers/stringhelper.h>
#include <log4cxx/patternlayout.h>
#include <log4cxx/basicconfigurator.h>

#include <cryptopp/aes.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>
#include <cryptopp/base64.h>
#include <cryptopp/osrng.h>

#include <fstream>
#include <string>

#include <openssl/aes.h> // Assuming you're using OpenSSL for encryption

using namespace log4cxx;
using namespace log4cxx::spi;
using namespace log4cxx::helpers;
using namespace CryptoPP;

namespace com::github::doevelopper::atlas::logging
{
    class EncryptedFileAppender : public AppenderSkeleton
    {
        File file;
        bool append;
        std::ofstream fileStream;
        std::string encryptionKey;

    public:

        EncryptedFileAppender() noexcept;
        EncryptedFileAppender(const EncryptedFileAppender&) = delete;
        EncryptedFileAppender(EncryptedFileAppender&&) = default;
        EncryptedFileAppender& operator=(const EncryptedFileAppender&) = delete;
        EncryptedFileAppender& operator=(EncryptedFileAppender&&) = default;
        virtual ~EncryptedFileAppender() noexcept;

        virtual void append(const log4cxx::spi::LoggingEventPtr& event);
    // protected:
    // private:
    // };
public:
    EncryptedFileAppender(const LogString& name, const File& file, bool append, const LayoutPtr& layout, const std::string& key)
        : AppenderSkeleton(name, layout), file(file), append(append), encryptionKey(key) {}

    virtual ~EncryptedFileAppender() {
        close();
    }

    virtual void close() override {
        if (fileStream.is_open()) {
            fileStream.close();
        }
    }

    virtual bool requiresLayout() const override { return true; }

    virtual void activateOptions() override {
        AppenderSkeleton::activateOptions();
        fileStream.open(file.getPath().c_str(), std::ios::out | (append ? std::ios::app : std::ios::trunc));
        if (!fileStream.is_open()) {
            LOG4CXX_ERROR(logger, "Failed to open log file: " << file.getPath());
        }
    }

    virtual void append(const LoggingEventPtr& event) override {
        if (!fileStream.is_open()) return;

        std::string formattedMessage = layout->format(event);
        std::string encryptedMessage = encrypt(formattedMessage, encryptionKey);
        std::string base64Encrypted = base64_encode(encryptedMessage);

        fileStream << base64Encrypted << std::endl;
    }

private:
    std::string encrypt(const std::string& plainText, const std::string& key) {
        std::string encryptedIVCiphertext;
        byte iv[AES::BLOCKSIZE];
        OS_GenerateRandomBlock(true, iv, sizeof(iv));

        encryptedIVCiphertext.append(reinterpret_cast<char*>(iv), sizeof(iv));

        AES::Encryption aesEncryption(reinterpret_cast<const byte*>(key.c_str()), key.size());
        CBC_Mode<AES>::Encryption cbcEncryption(aesEncryption, iv, sizeof(iv));

        std::string ciphertext;
        StreamTransformationFilter stfEncryptor(cbcEncryption, new StringSink(ciphertext));
        stfEncryptor.Put(reinterpret_cast<const byte*>(plainText.c_str()), plainText.size());
        stfEncryptor.MessageEnd();

        encryptedIVCiphertext.append(ciphertext);
        return encryptedIVCiphertext;
    }

    std::string base64_encode(const std::string& data) {
        std::string encoded;
        StringSource(data, true,
            new Base64Encoder(
                new StringSink(encoded)
            )
        );
        return encoded;
    }
};

// int main() {
//     LoggerPtr rootLogger = Logger::getRootLogger();
//     LayoutPtr layout(new PatternLayout("%d{ISO8601} [%t] %-5p %c %x - %m%n"));
//
//     File logFile("encrypted.log");
//     bool appendFlag = true;
//     std::string encryptionKey = "a16ByteKey123456"; // Must be 16, 24, or 32 bytes
//
//     EncryptedFileAppender* appender = new EncryptedFileAppender(
//         LOG4CXX_STR("EncryptedFile"),
//         logFile,
//         appendFlag,
//         layout,
//         encryptionKey
//     );
//
//     appender->activateOptions();
//     rootLogger->addAppender(appender);
//
//     LOG4CXX_INFO(rootLogger, "Sensitive data: 123456");
//     LOG4CXX_DEBUG(rootLogger, "Secret info: abcdefg");
//
//     appender->close();
//     delete appender;
//
//     return 0;
// }
}

#endif
