#pragma once

#include <list>
#include <functional>

namespace lgr3k
{
    template <class T>
    class SortedCircularBuffer {
    public:
        
        explicit SortedCircularBuffer(size_t size, std::function<void(T)> popCallback) 
            : mMaxSize(size)
            , mPopCallback(popCallback)
        {
        }

        void put(T item);
        void popToCallback();
        void popAllToCallback();
        void reset();
        bool isEmpty() const;

    protected:
        std::list<T> mBuffer; // TODO maybe change to map
        const size_t mMaxSize;
        bool mFull{false};
        std::function<void(T)> mPopCallback;
    };

    template<class T>
    void SortedCircularBuffer<T>::put(T item)
    {
        auto insIt = mBuffer.end();
        for (auto it = mBuffer.rbegin(); it != mBuffer.rend(); it++)
        {
            if (item >= *it)
            {
                insIt = mBuffer.insert(it.base(), std::move(item));
                break;
            }
        }
        if (insIt == mBuffer.end())
        {
            mBuffer.push_front(std::move(item));
        }
        if (mBuffer.size() > mMaxSize)
        {
            popToCallback();
        }
    }



    template<class T>
    void SortedCircularBuffer<T>::reset()
    {
        mBuffer.clear();
    }

    template<class T>
    bool SortedCircularBuffer<T>::isEmpty() const
    {
        return mBuffer.empty();
    }

    template<class T>
    void SortedCircularBuffer<T>::popToCallback()
    {
        mPopCallback(std::move(mBuffer.front()));
        mBuffer.pop_front();
    }

    template<class T>
    void SortedCircularBuffer<T>::popAllToCallback()
    {
        while(!isEmpty)
        {
            popToCallback();
        }
    }

} // namespace lgr3k
