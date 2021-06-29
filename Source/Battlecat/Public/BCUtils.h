#pragma once

class BCUtils
{
public:
    template <typename T>
    static T* GetBCPlayerComponent(APawn* PlayerPawn)
    {
        if (!PlayerPawn) return nullptr;

        const auto Component = PlayerPawn->GetComponentByClass(T::StaticClass());
        return Cast<T>(Component);
    }
};