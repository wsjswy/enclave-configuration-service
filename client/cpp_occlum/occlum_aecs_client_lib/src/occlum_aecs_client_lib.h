#ifndef OCCLUM_AECS_CLIENT_LIB_H_
#define OCCLUM_AECS_CLIENT_LIB_H_

#include <string>
#include "attestation/common/error.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Get Secret for TEE application and save to file
 *
 * @param[in] aecs_server_endpoint
 * @param[in] aecs_server_policy
 * @param[in] secret_service
 * @param[in] secret_name
 * @param[in] nonce
 * @param[in] save_file_name
 * @return int Error code
 */
TeeErrorCode aecs_client_get_secret_to_file(
    const std::string& aecs_server_endpoint,
    const std::string& aecs_server_policy,
    const std::string& secret_service,
    const std::string& secret_name,
    const std::string& nonce,
    const std::string& save_file_name);

/**
 * @brief Get Secret for TEE application
 *
 * @param[in] aecs_server_endpoint
 * @param[in] aecs_server_policy
 * @param[in] secret_service
 * @param[in] secret_name
 * @param[in] nonce
 * @param[out] secret Json-format secret
 * @return int Error code
 */
TeeErrorCode aecs_client_get_secret(const std::string& aecs_server_endpoint,
                                    const std::string& aecs_server_policy,
                                    const std::string& secret_service,
                                    const std::string& secret_name,
                                    const std::string& nonce,
                                    std::string* secret);

/**
 * @brief Create Trusted application bound secret
 *
 * @details Trusted application bound secret means the secret can only
 *          be used and delete by the trusted application which create it.
 *
 * @param[in] aecs_server_endpoint
 * @param[in] aecs_server_policy
 * @param[in] secret_policy_file defined how to create the secret
 * @return int Error code
 */
TeeErrorCode aecs_client_create_secret(const std::string& aecs_server_endpoint,
                                       const std::string& aecs_server_policy,
                                       const std::string& secret_policy_file);

/**
 * @brief Destroy Trusted application bound secret
 *
 * @param[in] aecs_server_endpoint
 * @param[in] aecs_server_policy
 * @param[in] secret_name
 * @return int Error code
 */
TeeErrorCode aecs_client_destroy_secret(const std::string& aecs_server_endpoint,
                                        const std::string& aecs_server_policy,
                                        const std::string& secret_name);

#ifdef __cplusplus
}
#endif

#endif  // OCCLUM_AECS_CLIENT_LIB_H_
