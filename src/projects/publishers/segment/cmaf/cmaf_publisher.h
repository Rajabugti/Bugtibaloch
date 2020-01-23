//==============================================================================
//
//  OvenMediaEngine
//
//  Created by Hyunjun Jang
//  Copyright (c) 2019 AirenSoft. All rights reserved.
//
//==============================================================================
#pragma once

#include "publishers/segment/dash/dash_publisher.h"

// TODO(Dimiden) : Change class name such as LLDashPublisher or CmafDashPublisher
class CmafPublisher : public DashPublisher
{
public:
	static std::shared_ptr<CmafPublisher> Create(std::map<int, std::shared_ptr<HttpServer>> &http_server_manager,
												 const cfg::Server &server_config,
												 const info::Host &host_info,
												 const std::shared_ptr<MediaRouteInterface> &router);

	CmafPublisher(PrivateToken token, const cfg::Server &server_config, const info::Host &host_info, const std::shared_ptr<MediaRouteInterface> &router);

private:
	//--------------------------------------------------------------------
	// Implementation of SegmentPublisher
	//--------------------------------------------------------------------
	bool Start(std::map<int, std::shared_ptr<HttpServer>> &http_server_manager) override;

	//--------------------------------------------------------------------
	// Implementation of Publisher
	//--------------------------------------------------------------------
	std::shared_ptr<Application> OnCreatePublisherApplication(const info::Application &application_info) override;

	PublisherType GetPublisherType() const override
	{
		return PublisherType::Cmaf;
	}

	const char *GetPublisherName() const override
	{
		return "CMAF";
	}
};