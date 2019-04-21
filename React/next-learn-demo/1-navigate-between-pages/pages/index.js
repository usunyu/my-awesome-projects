import Link from 'next/link'

export default function Index() {
  return (
    <div>
      <Link href="/about">
        <button>Go to About Page</button>
      </Link>
      <p>Hello Next.js</p>
    </div>
  )
}
