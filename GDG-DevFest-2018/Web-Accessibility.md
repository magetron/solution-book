# Web Accessibility

Websites should be accessible.

Some websites are not build on responsive frameworks.

## Definition

### Initial Definition

Everyone can percevie, understand, navigate and interact with the web.

### Then ..

* Perceivable
* Operable
* Understandable
* Robust

## Why is it important ?

Making wrong assumptions that all users are not physically challenged.

> The power of the web is in its universality. Access by everyone regardless of disability is an essentail aspect.

20 % of people -> 1 billion require accessiblity features.

71 % users with disablities click away from websites without accessibility features.

## Types of disabilites

* Visual
* Auditory
* Motor / Mobility
* Cognitive / Intellectual 

### Limited Mobility

* Permanent
* Temporary
* Situational

> Therefore we use assistive technologies.

## Standards to tackle the issue

### W3C -> WCAG 2.1 

Guideline to tackle such problem.

Assistive Technology is a "middleman" between web and user.

> Applcation -> Accessibility Tree -> Assistive Technology -> User

### WAI - ARIA

A specification with additional HTML tags.

DOM + ARIA -> accessibility tree

> ARIA - a way to add missing semantics

* roles
* states
* properties

### Button

#### Example

Bad idea : <div class='btn'>Search</div>

Good idea : <button class='btn'>Search</button>

### Navigation Landmarks

* <header>
* <footer>
* <nav>
* <main>
* <aside>

### Tab Order

Dom elements receive focus when `TAB` gets pressed.

Tab order should follow the order of the visual layout. 

__Every element should receive TAB focus__

### Use ARIA - Attributes

#### Example

<p tabindex="0">I am <b>first</b> paragraph.</p>
<p tabindex="0">I am <b>last</b> paragraph.</p>

<button>I am button with outlone: none</button>

Bad example:
<button class="btn"></button>

Good example:
<button aria-lable="Delete"></button>

### Color Contrast Ratio

[Online Tester](https://webaim.org/resoucres/contrastchecker)

> 4.5 : 1 Normal Text

> 3 : 1 Large Text 

## Testing tool

* aXe
	aXe-core for automated testing

* WAVE
* Lighthouse
	built-in devtools

All Browser Extension

Do some manual work ...

* Try to use your website with just keyboard.
* Download a screen reader and test with it.
* Add NoCoffee extension to test contrast and see if visually impaired people can see it.


> Small changes make big difference

## Resources
* Web Acessibility - Udacity course
* Accessibility Fundamentals - a11y guide
* WebAIM checklist
* WAI-ARIA
* WCAG

## Notes to myself

> Start a new website project with accessibility in mind.
> Make website user-friendly for all users.


