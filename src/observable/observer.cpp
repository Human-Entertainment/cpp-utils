#include <vector>
#include <functional>

/**
 * @brief An observer and emitter of new events over time
 * @note events are not stored
 * @tparam Value The type of the event to be emitted
 */
template<typename Value>  
class Observer 
{
public:
    Observer()
    {}

    /**
     * @brief Emit a new event to all listeners
     * 
     * @param value The event to be emitted
     */
    void emit(const Value& value)
    {
        for(const auto listener : listeners)
            listener(value);
    }

    /**
    * @brief A callback function, to be called on new event.
    * @param listener the function to be called
    */
    void observe(std::function<void(Value)> listener)
    {
        listeners.push_back(listener);
    }

private:
    std::vector<std::function<void(const Value&)>> listeners;
};