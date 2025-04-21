<!--
 * @Author: baineng.shou baineng.shou@nio.com
 * @Date: 2025-04-20 20:35:04
 * @LastEditors: baineng 491636840@qq.com
 * @LastEditTime: 2025-04-21 11:21:27
 * @FilePath: /vold/123.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->

[mermaid官方文档](https://mermaid.js.org/syntax/flowchart.html)

```mermaid
graph TB
    subgraph Host_OS
        Docker_Engine-->|调用| Linux_Kernel
        Linux_Kernel-->Namespace["Namespace (PID/Net/UTS等)"]
        Linux_Kernel-->Cgroups["Cgroups (资源控制)"]
        Linux_Kernel-->UnionFS["UnionFS (镜像分层)"]
    end
    Docker_Engine-->Container1-->Image1
    Docker_Engine-->Container2-->Image2
```
```mermaid
sequenceDiagram
    rect rgba(0, 255, 0, 0.1)
        Alice->>Bob: Step 1
        Bob-->>Alice: Step 2
        Bob-->>Alice: Step 2
    end
```

```mermaid
sequenceDiagram
    Alice->>Bob: Hello Bob, how are you ?
    Bob->>Alice: Fine, thank you. And you?
    create participant Carl
    Alice->>Carl: Hi Carl!
    create actor D as Donald
    Carl->>D: Hi!
    destroy Carl
    Alice-xCarl: We are too many
    destroy Bob
    Bob->>Alice: I agree
```

```mermaid
sequenceDiagram
    Alice->>John: Hello John, how are you?
    activate John
    John-->>Alice: Great!
    deactivate John
```


```mermaid
sequenceDiagram
    Alice->>+John: Hello John, how are you?
    Alice->>+John:sudo apt install docker-ce docker-ce-cli containerd.io?
    John-->>-Alice: Hi Alice, I can hear you!
    John-->>Alice: I feel great!
```

```mermaid
sequenceDiagram
    par Alice to Bob
        Alice->>Bob: Go help John
    and Alice to John
        Alice->>John: I want this done today
        par John to Charlie
            John->>Charlie: Can we do this today?
        and John to Diana
            John->>Diana: Can you help us today?
        end
    end
```


```mermaid
sequenceDiagram
    Consumer-->API: Book something
    API-->BookingService: Start booking process
    break when the booking process fails
        API-->Consumer: show failure
    end
    API-->BillingService: Start billing process
```

# class diagram

```mermaid
---
title: Animal example
---
classDiagram
    note "From Duck till Zebra"
    Animal <|-- Duck
    note for Duck "can fly\ncan swim\ncan dive\ncan help in debugging"
    Animal <|-- Fish
    Animal <|-- Zebra
    Animal : +int age
    Animal : +String gender
    Animal: +isMammal()
    Animal: +mate()
    class Duck{
        +String beakColor
        +swim()
        +quack()
    }
    class Fish{
        -int sizeInFeet
        -canEat()
    }
    class Zebra{
        +bool is_wild
        +run()
    }
```