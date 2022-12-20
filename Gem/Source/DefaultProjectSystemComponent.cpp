
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "DefaultProjectSystemComponent.h"

namespace DefaultProject
{
    void DefaultProjectSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<DefaultProjectSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<DefaultProjectSystemComponent>("DefaultProject", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void DefaultProjectSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("DefaultProjectService"));
    }

    void DefaultProjectSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("DefaultProjectService"));
    }

    void DefaultProjectSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void DefaultProjectSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    DefaultProjectSystemComponent::DefaultProjectSystemComponent()
    {
        if (DefaultProjectInterface::Get() == nullptr)
        {
            DefaultProjectInterface::Register(this);
        }
    }

    DefaultProjectSystemComponent::~DefaultProjectSystemComponent()
    {
        if (DefaultProjectInterface::Get() == this)
        {
            DefaultProjectInterface::Unregister(this);
        }
    }

    void DefaultProjectSystemComponent::Init()
    {
    }

    void DefaultProjectSystemComponent::Activate()
    {
        DefaultProjectRequestBus::Handler::BusConnect();
    }

    void DefaultProjectSystemComponent::Deactivate()
    {
        DefaultProjectRequestBus::Handler::BusDisconnect();
    }
}
