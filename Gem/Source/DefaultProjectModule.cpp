
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "DefaultProjectSystemComponent.h"

namespace DefaultProject
{
    class DefaultProjectModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(DefaultProjectModule, "{61F86D31-F122-4801-B5D0-4C454879C18F}", AZ::Module);
        AZ_CLASS_ALLOCATOR(DefaultProjectModule, AZ::SystemAllocator, 0);

        DefaultProjectModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                DefaultProjectSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<DefaultProjectSystemComponent>(),
            };
        }
    };
}// namespace DefaultProject

AZ_DECLARE_MODULE_CLASS(Gem_DefaultProject, DefaultProject::DefaultProjectModule)
